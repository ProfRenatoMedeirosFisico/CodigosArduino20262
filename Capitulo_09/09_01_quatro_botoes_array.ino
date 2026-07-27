// Numero total de botoes
const byte NUM_BOTOES = 4;
// Pinos utilizados pelos botoes
const byte pinosBotoes[NUM_BOTOES] = {8, 9, 10, 11};

void setup() {
  Serial.begin(9600);
  // Configura todos os botoes
  for (byte i = 0; i < NUM_BOTOES; i++) {
    pinMode(pinosBotoes[i], INPUT_PULLUP);
  }
}

void loop() {
  // Verifica cada botao
  for (byte i = 0; i < NUM_BOTOES; i++) {
    if (digitalRead(pinosBotoes[i]) == LOW) {
      Serial.print("Botao ");
      Serial.print(i + 1);
      Serial.println(" pressionado!");
    }
  }
  delay(100);
}
