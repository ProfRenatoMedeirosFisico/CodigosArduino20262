#include <Servo.h>
Servo meuServo;

void setup() {
  meuServo.attach(9);
  // Posicao central aproximada
  meuServo.write(90);
  // Tempo para o servo atingir a posicao
  delay(1000);
}

void loop() {
  // Nenhuma acao necessaria
}
