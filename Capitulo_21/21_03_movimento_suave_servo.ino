#include <Servo.h>
Servo meuServo;
void setup() {
  meuServo.attach(9);
  meuServo.write(90);
  delay(1000);
}

void loop() {
  for (int angulo = 0; angulo <= 180; angulo++) {
    meuServo.write(angulo);
    delay(15);
  }
  for (int angulo = 180; angulo >= 0; angulo--) {
    meuServo.write(angulo);
    delay(15);
  }
}
