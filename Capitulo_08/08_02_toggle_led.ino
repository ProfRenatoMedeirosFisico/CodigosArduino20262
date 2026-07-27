#define PIN_BOTAO 7
#define PIN_LED   8
bool estadoLED = false;
bool ultimoEstadoBotao = HIGH;

void setup() {
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_BOTAO, INPUT_PULLUP);
  digitalWrite(PIN_LED, LOW);
}

void loop() {
  bool estadoAtualBotao = digitalRead(PIN_BOTAO);
  // Detecta a transicao HIGH -> LOW
  if (ultimoEstadoBotao == HIGH &&
      estadoAtualBotao == LOW) {
    estadoLED = !estadoLED;
    digitalWrite(PIN_LED,
                 estadoLED ? HIGH : LOW);
    // Debounce simples
    delay(50);
  }
  ultimoEstadoBotao = estadoAtualBotao;
}
