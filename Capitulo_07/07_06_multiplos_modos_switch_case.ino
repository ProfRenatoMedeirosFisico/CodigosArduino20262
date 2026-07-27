int leds[] = {2, 3, 4, 5, 6, 7};
int numLeds = 6;
int modo = 2;

void todosDesligados() {
  for (int i = 0; i < numLeds; i++) {
    digitalWrite(leds[i], LOW);
  }
}

void piscarTodos() {
  for (int i = 0; i < numLeds; i++) {
    digitalWrite(leds[i], HIGH);
  }
  delay(300);
  todosDesligados();
  delay(300);
}

void sequencial() {
  for (int i = 0; i < numLeds; i++) {
    todosDesligados();
    digitalWrite(leds[i], HIGH);
    delay(150);
  }
}

void knightRider() {
  for (int i = 0; i < numLeds; i++) {
    todosDesligados();
    digitalWrite(leds[i], HIGH);
    delay(80);
  }

  for (int i = numLeds - 2; i >= 1; i--) {
    todosDesligados();
    digitalWrite(leds[i], HIGH);
    delay(80);
  }
}

void setup() {
  for (int i = 0; i < numLeds; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
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
