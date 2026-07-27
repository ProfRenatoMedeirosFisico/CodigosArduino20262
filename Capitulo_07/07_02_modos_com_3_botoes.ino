const int botao1 = 8;
const int botao2 = 9;
const int botao3 = 10;
int modo = 1;

void setup() {
  pinMode(botao1, INPUT_PULLUP);
  pinMode(botao2, INPUT_PULLUP);
  pinMode(botao3, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(botao1) == LOW) {
    modo = 1;
  }
  if (digitalRead(botao2) == LOW) {
    modo = 2;
  }
  if (digitalRead(botao3) == LOW) {
    modo = 3;
  }

  switch (modo) {
    case 1:
      Serial.println("Modo 1: Semaforo");
      break;
    case 2:
      Serial.println("Modo 2: Knight Rider");
      break;
    case 3:
      Serial.println("Modo 3: Fade");
      break;
  }
  delay(100);
}
