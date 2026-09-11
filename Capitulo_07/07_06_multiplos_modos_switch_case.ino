int leds[] = {2, 3, 4, 5, 6, 7};
int numLeds = 6;

int botao1 = 8;   // pressionar -> modo 1 (piscarTodos)
int botao2 = 9;   // pressionar -> modo 2 (knightRider)
int botao3 = 10;  // pressionar -> modo 3 (sequencial)

int modo = 2;

void todosDesligados() {
  for (int i = 0; i < numLeds; i++) {
    digitalWrite(leds[i], LOW);
  }
}

void lerBotoes() {
  if (digitalRead(botao1) == LOW) modo = 1;
  if (digitalRead(botao2) == LOW) modo = 2;
  if (digitalRead(botao3) == LOW) modo = 3;
}

void piscarTodos() {
  int modoAoEntrar = modo;
  for (int i = 0; i < numLeds; i++) digitalWrite(leds[i], HIGH);
  delay(300);
  todosDesligados();
  delay(300);
  lerBotoes();
}

void sequencial() {
  for (int i = 0; i < numLeds; i++) {
    todosDesligados();
    digitalWrite(leds[i], HIGH);
    delay(150);
    lerBotoes();
    if (modo != 3) return;   // botão trocou o modo -> sai na hora
  }
}

void knightRider() {
  for (int i = 0; i < numLeds; i++) {
    todosDesligados();
    digitalWrite(leds[i], HIGH);
    delay(80);
    lerBotoes();
    if (modo != 2) return;
  }
  for (int i = numLeds - 2; i >= 1; i--) {
    todosDesligados();
    digitalWrite(leds[i], HIGH);
    delay(80);
    lerBotoes();
    if (modo != 2) return;
  }
}

void setup() {
  for (int i = 0; i < numLeds; i++) {
    pinMode(leds[i], OUTPUT);
  }
  pinMode(botao1, INPUT_PULLUP);
  pinMode(botao2, INPUT_PULLUP);
  pinMode(botao3, INPUT_PULLUP);
}

void loop() {
  lerBotoes();

  switch (modo) {
    case 1:
      piscarTodos();
      break;
    case 2:
      knightRider();
      break;
    case 3:
      sequencial();
      break;
    default:
      todosDesligados();
      break;
  }
}
