#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Endereco obtido com o scanner I2C.
LiquidCrystal_I2C lcd(0x27, 16, 2);

const byte BTN_HORA = 6;
const byte BTN_MIN  = 7;

int horas = 12;
int minutos = 0;
int segundos = 0;

unsigned long ultimaAtualizacao = 0;

bool leituraAnteriorHora = HIGH;
bool leituraAnteriorMin  = HIGH;
bool estadoEstavelHora = HIGH;
bool estadoEstavelMin  = HIGH;

unsigned long instanteMudancaHora = 0;
unsigned long instanteMudancaMin  = 0;

const unsigned long TEMPO_DEBOUNCE = 40;

void setup() {
  lcd.init();
  lcd.backlight();

  pinMode(BTN_HORA, INPUT_PULLUP);
  pinMode(BTN_MIN, INPUT_PULLUP);

  lcd.setCursor(2, 0);
  lcd.print("Relogio UEG");
  lcd.setCursor(4, 1);
  lcd.print("12:00:00");

  delay(1500);

  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("HORARIO");

  // Inicia a referencia temporal somente apos a tela inicial.
  ultimaAtualizacao = millis();
}

void atualizarRelogio() {
  unsigned long agora = millis();

  // Recupera segundos caso o loop fique temporariamente ocupado.
  while (agora - ultimaAtualizacao >= 1000UL) {
    ultimaAtualizacao += 1000UL;
    segundos++;

    if (segundos >= 60) {
      segundos = 0;
      minutos++;
    }

    if (minutos >= 60) {
      minutos = 0;
      horas++;
    }

    if (horas >= 24) {
      horas = 0;
    }
  }
}

bool botaoFoiPressionado(byte pino,
                         bool &leituraAnterior,
                         bool &estadoEstavel,
                         unsigned long &instanteMudanca) {
  bool leituraAtual = digitalRead(pino);
  unsigned long agora = millis();

  if (leituraAtual != leituraAnterior) {
    instanteMudanca = agora;
    leituraAnterior = leituraAtual;
  }

  if ((agora - instanteMudanca) >= TEMPO_DEBOUNCE &&
      leituraAtual != estadoEstavel) {

    estadoEstavel = leituraAtual;

    if (estadoEstavel == LOW) {
      return true;
    }
  }

  return false;
}

void lerBotoes() {
  if (botaoFoiPressionado(BTN_HORA,
                          leituraAnteriorHora,
                          estadoEstavelHora,
                          instanteMudancaHora)) {
    horas = (horas + 1) % 24;
  }

  if (botaoFoiPressionado(BTN_MIN,
                          leituraAnteriorMin,
                          estadoEstavelMin,
                          instanteMudancaMin)) {
    minutos = (minutos + 1) % 60;
    segundos = 0;

    // Evita um segundo muito curto logo apos o ajuste.
    ultimaAtualizacao = millis();
  }
}

void imprimirDoisDigitos(int valor) {
  if (valor < 10) lcd.print("0");
  lcd.print(valor);
}

void exibirHora() {
  lcd.setCursor(4, 1);

  imprimirDoisDigitos(horas);
  lcd.print(":");
  imprimirDoisDigitos(minutos);
  lcd.print(":");
  imprimirDoisDigitos(segundos);
}

void loop() {
  lerBotoes();
  atualizarRelogio();
  exibirHora();
}
