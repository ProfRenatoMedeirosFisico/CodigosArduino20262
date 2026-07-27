#define PINO_POT A0

void setup() {
  Serial.begin(9600);
}

void loop() {
  int leitura = analogRead(PINO_POT);
  float tensao = leitura * (5.0 / 1023.0);
  Serial.print("ADC: ");
  Serial.print(leitura);
  Serial.print("  |  Tensao: ");
  Serial.print(tensao, 3);
  Serial.println(" V");
  delay(300);
}
