const int potenciometro = A0;
const int led = 9;

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  int leitura = analogRead(potenciometro);
  int brilho = map(leitura, 0, 1023, 0, 255);
  analogWrite(led, brilho);
  delay(10);
}
