#define PINO_POT A0
void setup() {
  Serial.begin(9600);
}

void loop() {
  int leitura = analogRead(PINO_POT);
  Serial.print("ADC = ");
  Serial.println(leitura);
  delay(200);
}
