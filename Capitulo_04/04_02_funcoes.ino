// Declaramos a funcao ANTES do setup() ou apos o loop()
// Esta funcao pisca um LED 'n' vezes com intervalo 't' ms
void piscarLED(int pino, int n, int t) {
  for (int i = 0; i < n; i++) {
    digitalWrite(pino, HIGH);
    delay(t);
    digitalWrite(pino, LOW);
    delay(t);
  }
}

// Funcao que retorna um valor
float celsiusParaFahrenheit(float c) {
  return (c * 9.0 / 5.0) + 32.0;
}

void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  piscarLED(13, 3, 200); // pisca pino 13, 3 vezes, intervalo 200ms
  Serial.println(celsiusParaFahrenheit(25.0)); // imprime 77.00
  delay(2000);
}
