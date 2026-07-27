#include <Wire.h>
#include <LiquidCrystal_I2C.h>
// Endereco obtido com o scanner I2C
LiquidCrystal_I2C lcd(0x27, 16, 2);
// Pinos dos botoes
const byte BTN_HORA = 6;
const byte BTN_MIN  = 7;
// Horario inicial
int horas = 12;
int minutos = 0;
int segundos = 0;
// Controle do tempo
unsigned long ultimaAtualizacao = 0;
// Estados anteriores dos botoes
bool estadoAnteriorHora = HIGH;
bool estadoAnteriorMin  = HIGH;

void setup() {
  // Inicializa LCD
  lcd.init();
  lcd.backlight();
  // Configura botoes com pull-up interno
  pinMode(BTN_HORA, INPUT_PULLUP);
  pinMode(BTN_MIN,  INPUT_PULLUP);
  // Mensagem inicial
  lcd.setCursor(2, 0);
  lcd.print("Relogio UEG");
  lcd.setCursor(4, 1);
  lcd.print("12:00:00");
  delay(1500);
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("HORARIO");
}

void atualizarRelogio() {
  unsigned long agora = millis();
  // Verifica se passou aproximadamente 1 segundo
  if (agora - ultimaAtualizacao >= 1000) {
    // Mantem a referencia temporal em passos de 1 s
    ultimaAtualizacao += 1000;
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

void lerBotoes() {
  bool estadoHora = digitalRead(BTN_HORA);
  bool estadoMin  = digitalRead(BTN_MIN);
  // Detecta o instante em que o botao de hora e pressionado
  if (estadoAnteriorHora == HIGH && estadoHora == LOW) {
    horas = (horas + 1) % 24;
  }
  // Detecta o instante em que o botao de minuto e pressionado
  if (estadoAnteriorMin == HIGH && estadoMin == LOW) {
    minutos = (minutos + 1) % 60;
    segundos = 0;
  }
  estadoAnteriorHora = estadoHora;
  estadoAnteriorMin  = estadoMin;
}

void imprimirDoisDigitos(int valor) {
  if (valor < 10) {
    lcd.print("0");
  }
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
