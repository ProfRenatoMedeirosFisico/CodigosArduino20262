/*
  TEMPLATE DIDATICO — ESTRUTURA DE UM PROJETO MAIOR

  Este arquivo NAO representa um projeto funcional completo.
  Ele serve como modelo para que a equipe organize o proprio codigo.

  Complete as funcoes, pinos, sensores, atuadores e bibliotecas
  de acordo com o projeto desenvolvido pelo grupo.
*/

#include <Servo.h>

// Inclua outras bibliotecas apenas se o seu projeto realmente usar.
// Exemplo:
// #include <LiquidCrystal_I2C.h>

// ------------------------------------------------
// DEFINICOES DE PINOS — EXEMPLOS
// ------------------------------------------------
#define PINO_SENSOR A0
#define PINO_LED    13

// ------------------------------------------------
// CONSTANTES — EXEMPLOS
// ------------------------------------------------
const float LIMIAR = 30.0;

// ------------------------------------------------
// VARIAVEIS GLOBAIS — EXEMPLOS
// ------------------------------------------------
float valorSensor = 0.0;
bool alarmeAtivo = false;

// ------------------------------------------------
// OBJETOS — CRIE APENAS OS NECESSARIOS
// ------------------------------------------------
// Servo meuServo;
// LiquidCrystal_I2C lcd(0x27, 16, 2);

// ------------------------------------------------
// FUNCOES AUXILIARES
// ------------------------------------------------
float lerSensor() {
  /*
    SUBSTITUA este conteudo pela leitura real do sensor.

    Exemplo:
      int leitura = analogRead(PINO_SENSOR);
      return leitura;
  */

  return 0.0;
}

void atualizarSaidas() {
  /*
    SUBSTITUA este conteudo pelas acoes do seu projeto.

    Exemplos:
      - atualizar LEDs;
      - movimentar motores ou servos;
      - atualizar o display;
      - acionar um buzzer;
      - enviar dados ao Monitor Serial.
  */
}

// ------------------------------------------------
// SETUP
// ------------------------------------------------
void setup() {
  Serial.begin(9600);

  pinMode(PINO_LED, OUTPUT);

  // Adicione aqui as demais inicializacoes.
}

// ------------------------------------------------
// LOOP PRINCIPAL
// ------------------------------------------------
void loop() {
  valorSensor = lerSensor();

  atualizarSaidas();

  delay(100);
}
