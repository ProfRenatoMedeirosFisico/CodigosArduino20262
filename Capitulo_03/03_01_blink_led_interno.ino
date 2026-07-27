// Blink - Pisca o LED interno do Arduino (pino 13)
// Este e o primeiro sketch de todo iniciante!

// A funcao setup() roda UMA UNICA VEZ ao ligar o Arduino
void setup() {
  // Configura o pino 13 como SAIDA digital
  // (o LED interno esta conectado ao pino 13)
  pinMode(13, OUTPUT);
}

// A funcao loop() roda CONTINUAMENTE, em laco infinito
void loop() {
  digitalWrite(13, HIGH);  // Liga o LED (5V no pino 13)
  delay(1000);              // Aguarda 1000 milissegundos (1 segundo)
  digitalWrite(13, LOW);   // Desliga o LED (0V no pino 13)
  delay(1000);              // Aguarda 1 segundo
}
// O ciclo: liga -> espera -> desliga -> espera -> repete
