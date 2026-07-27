int pinos[] = {2, 3, 4, 5, 6, 7};
int numLeds = 6;
int velocidade = 80;

void acenderSoEste(int pos) {
  // Desliga todos os LEDs
  for (int i = 0; i < numLeds; i++) {
    digitalWrite(pinos[i], LOW);
  }
  // Liga somente o LED selecionado
  if (pos >= 0 && pos < numLeds) {
    digitalWrite(pinos[pos], HIGH);
  }
}

void setup() {
  for (int i = 0; i < numLeds; i++) {
    pinMode(pinos[i], OUTPUT);
  }
}

void loop() {
  // Movimento da esquerda para a direita
  for (int i = 0; i < numLeds; i++) {
    acenderSoEste(i);
    delay(velocidade);
  }

  // Movimento da direita para a esquerda
  for (int i = numLeds - 2; i >= 1; i--) {
    acenderSoEste(i);
    delay(velocidade);
  }
}
