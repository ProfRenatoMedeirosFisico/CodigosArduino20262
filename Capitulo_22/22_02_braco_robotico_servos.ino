// Braco robotico simples
// Dois servos controlados por dois potenciometros
#include <Servo.h>
Servo servoBase;
Servo servoBraco;
// Entradas analogicas
const int POT_BASE  = A0;
const int POT_BRACO = A1;
// Sinais dos servos
const int PIN_SERVO_BASE  = 9;
const int PIN_SERVO_BRACO = 10;
// Limites do servo do braco
const int ANGULO_MIN_BRACO = 10;
const int ANGULO_MAX_BRACO = 160;

void setup() {
  servoBase.attach(PIN_SERVO_BASE);
  servoBraco.attach(PIN_SERVO_BRACO);
  // Posicao inicial
  servoBase.write(90);
  servoBraco.write(90);
  delay(500);
  Serial.begin(9600);
}

void loop() {
  // Le os potenciometros
  int potBase  = analogRead(POT_BASE);
  int potBraco = analogRead(POT_BRACO);
  // Converte as leituras em angulos
  int anguloBase =
      map(potBase, 0, 1023, 0, 180);
  int anguloBraco =
      map(potBraco, 0, 1023,
          ANGULO_MIN_BRACO,
          ANGULO_MAX_BRACO);
  // Move os servos
  servoBase.write(anguloBase);
  servoBraco.write(anguloBraco);
  // Monitor Serial
  Serial.print("Base: ");
  Serial.print(anguloBase);
  Serial.print(" graus | Braco: ");
  Serial.print(anguloBraco);
  Serial.println(" graus");
  delay(20);
}
