// Entradas digitais - Push-button + LED
#define PIN_BOTAO 7
#define PIN_LED   8

void setup() {
  // LED conectado ao pino 8
  pinMode(PIN_LED, OUTPUT);
  // Ativa o resistor interno de pull-up
  pinMode(PIN_BOTAO, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  int estadoBotao = digitalRead(PIN_BOTAO);
  // Com INPUT_PULLUP:
  // LOW  = botao pressionado
  // HIGH = botao solto
  if (estadoBotao == LOW) {
    digitalWrite(PIN_LED, HIGH);
    Serial.println("Botao pressionado - LED ligado");
  } else {
    digitalWrite(PIN_LED, LOW);
    Serial.println("Botao solto - LED desligado");
  }
  delay(100);
}
