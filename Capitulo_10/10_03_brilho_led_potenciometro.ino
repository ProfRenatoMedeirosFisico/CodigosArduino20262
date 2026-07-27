#define PINO_POT A0
#define PINO_LED 9

void setup() {
  pinMode(PINO_LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Le o potenciometro
  int leituraADC = analogRead(PINO_POT);
  // Converte ADC (0-1023) para PWM (0-255)
  int brilho = map(leituraADC, 0, 1023, 0, 255);
  // Controla o LED
  analogWrite(PINO_LED, brilho);
  // Exibe os valores
  Serial.print("ADC: ");
  Serial.print(leituraADC);
  Serial.print(" | PWM: ");
  Serial.println(brilho);
  delay(50);
}
