#define PINO_LDR A0

void setup() {
  Serial.begin(9600);
}

void loop() {
  int leitura = analogRead(PINO_LDR);
  float tensao = leitura * (5.0 / 1023.0);
  Serial.print("ADC = ");
  Serial.print(leitura);
  Serial.print(" | Tensao = ");
  Serial.print(tensao, 2);
  Serial.println(" V");
  delay(500);
}
