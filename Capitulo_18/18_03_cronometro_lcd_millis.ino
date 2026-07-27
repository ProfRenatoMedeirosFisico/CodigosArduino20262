#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const byte BTN_START = 7;
const byte BTN_RESET = 8;

bool rodando = false;

unsigned long tempoInicio = 0;
unsigned long tempoAcumulado = 0;

bool ultimoBtnStart = HIGH;
bool ultimoBtnReset = HIGH;

void exibirTempo(unsigned long tempo) {
  unsigned long minutos = tempo / 60000UL;
  unsigned long segundos = (tempo % 60000UL) / 1000UL;
  unsigned long milissegundos = tempo % 1000UL;

  lcd.setCursor(2, 1);

  if (minutos < 10) lcd.print("0");
  lcd.print(minutos);
  lcd.print(":");

  if (segundos < 10) lcd.print("0");
  lcd.print(segundos);
  lcd.print(".");

  if (milissegundos < 100) lcd.print("0");
  if (milissegundos < 10) lcd.print("0");
  lcd.print(milissegundos);
}

void setup() {
  lcd.begin(16, 2);

  pinMode(BTN_START, INPUT_PULLUP);
  pinMode(BTN_RESET, INPUT_PULLUP);

  lcd.setCursor(0, 0);
  lcd.print("  Cronometro");
  lcd.setCursor(0, 1);
  lcd.print("  00:00.000");
}

void loop() {
  bool btnStart = digitalRead(BTN_START);
  bool btnReset = digitalRead(BTN_RESET);

  // START/PAUSE: reage apenas a transicao HIGH -> LOW.
  if (ultimoBtnStart == HIGH && btnStart == LOW) {
    rodando = !rodando;

    if (rodando) {
      tempoInicio = millis();
    } else {
      tempoAcumulado += millis() - tempoInicio;
    }

    delay(40);  // debounce simples
  }

  // RESET: tambem reage apenas a transicao HIGH -> LOW.
  if (ultimoBtnReset == HIGH && btnReset == LOW) {
    rodando = false;
    tempoAcumulado = 0;
    tempoInicio = millis();

    delay(40);  // debounce simples
  }

  ultimoBtnStart = btnStart;
  ultimoBtnReset = btnReset;

  unsigned long tempoTotal = tempoAcumulado;

  if (rodando) {
    tempoTotal += millis() - tempoInicio;
  }

  exibirTempo(tempoTotal);
}
