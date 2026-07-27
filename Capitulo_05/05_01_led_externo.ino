// Define o pino do LED com uma constante (boa pratica!)
#define LED_PIN 8

void setup() {
  pinMode(LED_PIN, OUTPUT); // configura pino 8 como saida digital
}

void loop() {
  digitalWrite(LED_PIN, HIGH); // liga o LED (5V no pino 8)
  delay(500);                  // aguarda 500 ms
  digitalWrite(LED_PIN, LOW);  // desliga o LED (0V no pino 8)
  delay(500);                  // aguarda 500 ms
}
