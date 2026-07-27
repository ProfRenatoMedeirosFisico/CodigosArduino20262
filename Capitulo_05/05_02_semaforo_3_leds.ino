// Semaforo com 3 LEDs
#define LED_VERMELHO 11
#define LED_AMARELO  12
#define LED_VERDE    13

void setup() {
  pinMode(LED_VERMELHO, OUTPUT);
  pinMode(LED_AMARELO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
}

// Funcao auxiliar: desliga todos os LEDs
void desligaTodos() {
  digitalWrite(LED_VERMELHO, LOW);
  digitalWrite(LED_AMARELO, LOW);
  digitalWrite(LED_VERDE, LOW);
}

void loop() {
  // VERDE: pedestres nao passam, carros passam (5 segundos)
  desligaTodos();
  digitalWrite(LED_VERDE, HIGH);
  delay(5000);

  // AMARELO: atencao, preparar para parar (2 segundos)
  desligaTodos();
  digitalWrite(LED_AMARELO, HIGH);
  delay(2000);

  // VERMELHO: carros param, pedestres atravessam (4 segundos)
  desligaTodos();
  digitalWrite(LED_VERMELHO, HIGH);
  delay(4000);
}
