// Servo controlado por potenciometro
#include <Servo.h>
Servo meuServo;
const int PINO_POT   = A0;
const int PINO_SERVO = 9;

void setup() {
  meuServo.attach(PINO_SERVO);
  Serial.begin(9600);
}

void loop() {
  // Le o potenciometro: valores entre 0 e 1023
  int leituraPot = analogRead(PINO_POT);
  // Converte a escala 0-1023 para 0-180 graus
  int angulo = map(leituraPot, 0, 1023, 0, 180);
  // Posiciona o servo
  meuServo.write(angulo);
  // Exibe os valores no Monitor Serial
  Serial.print("Potenciometro: ");
  Serial.print(leituraPot);
  Serial.print(" | Angulo: ");
  Serial.print(angulo);
  Serial.println(" graus");
  delay(15);
}
