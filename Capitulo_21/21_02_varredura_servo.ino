#include <Servo.h>
Servo meuServo;

void setup() {
  meuServo.attach(9);
  // Inicializa aproximadamente no centro
  meuServo.write(90);
  delay(1000);
  Serial.begin(9600);
}

void loop() {
  // Movimento de 0 ate 180 graus
  for (int angulo = 0; angulo <= 180; angulo += 15) {
    meuServo.write(angulo);
    Serial.print("Angulo: ");
    Serial.print(angulo);
    Serial.println(" graus");
    delay(500);
  }
  // Movimento de 180 ate 0 graus
  for (int angulo = 180; angulo >= 0; angulo -= 15) {
    meuServo.write(angulo);
    Serial.print("Angulo: ");
    Serial.print(angulo);
    Serial.println(" graus");
    delay(500);
  }
}
