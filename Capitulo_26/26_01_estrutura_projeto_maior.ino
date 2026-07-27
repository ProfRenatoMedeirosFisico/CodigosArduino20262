// ================================================
// NOME DO PROJETO
// Autores: Nome1, Nome2
// Data: XX/XX/XXXX
// Descricao: breve descricao do projeto
// ================================================
// === BIBLIOTECAS ===
#include <Servo.h>
// #include <LiquidCrystal_I2C.h>
// === DEFINICOES DE PINOS ===
#define PINO_SENSOR  A0
#define PINO_LED     13
// === CONSTANTES DO PROJETO ===
const float LIMIAR = 30.0;
const int VELOCIDADE_MAX = 200;
// === VARIAVEIS GLOBAIS ===
float temperatura = 0;
bool alarmeAtivo = false;
// === OBJETOS ===
// Servo meuServo;
// LiquidCrystal_I2C lcd(0x27, 16, 2);
// ================================================
// FUNCOES AUXILIARES
// ================================================
float lerSensor() {
  // Ler e processar o sensor
  return 0;
}

void atualizarSaidas() {

  // Atualizar LEDs, motores, display etc.
}
// ================================================
// SETUP
// ================================================

void setup() {
  Serial.begin(9600);
  pinMode(PINO_LED, OUTPUT);
  // Outras inicializacoes...
}
// ================================================
// LOOP PRINCIPAL
// ================================================

void loop() {
  temperatura = lerSensor();
  atualizarSaidas();
  delay(100);
}
