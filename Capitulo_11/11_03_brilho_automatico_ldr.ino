#define PINO_LDR A0
#define PINO_LED 9

void setup() {
  pinMode(PINO_LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int leitura = analogRead(PINO_LDR);
  int brilho = map(leitura, 0, 1023, 255, 0);
  analogWrite(PINO_LED, brilho);
  Serial.print("ADC: ");
  Serial.print(leitura);
  Serial.print(" | PWM: ");
  Serial.println(brilho);
  delay(100);
}
