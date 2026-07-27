// =============================================
// Sensor ultrassonico HC-SR04
// Trena eletronica
// =============================================
#define PINO_TRIG 8
#define PINO_ECHO 9

void setup() {
  pinMode(PINO_TRIG, OUTPUT);
  pinMode(PINO_ECHO, INPUT);
  // Mantem inicialmente o TRIG em nivel LOW
  digitalWrite(PINO_TRIG, LOW);
  Serial.begin(9600);
  Serial.println("================================");
  Serial.println("   Trena Eletronica HC-SR04");
  Serial.println("================================");
}

float medirDistancia() {
  digitalWrite(PINO_TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(PINO_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PINO_TRIG, LOW);
  unsigned long duracao = pulseIn(PINO_ECHO, HIGH, 30000UL);
  if (duracao == 0) {
    return -1.0;
  }
  float distancia = duracao * 0.0343 / 2.0;
  return distancia;
}

void loop() {
  float distancia = medirDistancia();
  if (distancia < 0) {
    Serial.println("Objeto fora da faixa ou sem eco");
  } else {
    Serial.print("Distancia: ");
    Serial.print(distancia, 1);
    Serial.println(" cm");
  }
  delay(500);
}
