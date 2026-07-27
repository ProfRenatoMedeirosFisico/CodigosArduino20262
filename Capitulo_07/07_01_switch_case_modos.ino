int modo = 2;

void setup() {
  Serial.begin(9600);
}

void loop() {
  switch (modo) {
    case 1:
      Serial.println("Modo 1: lento");
      break;
    case 2:
      Serial.println("Modo 2: normal");
      break;
    case 3:
      Serial.println("Modo 3: rapido");
      break;
    default:
      Serial.println("Modo invalido");
      break;
  }
  delay(1000);
}
