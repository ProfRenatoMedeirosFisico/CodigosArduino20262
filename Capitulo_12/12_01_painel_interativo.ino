#define BTN_A 8
#define BTN_B 9
#define BTN_C 10
#define LED_MAIN 6
#define LED_MODO1 2
#define LED_MODO2 3
#define LED_MODO3 4
#define POT_PIN A0
#define LDR_PIN A1
int modoAtual = 1;
int brilhoFade = 0;
int passoFade = 5;
void setup() {
  pinMode(BTN_A, INPUT_PULLUP);
  pinMode(BTN_B, INPUT_PULLUP);
  pinMode(BTN_C, INPUT_PULLUP);
  pinMode(LED_MAIN, OUTPUT);
  pinMode(LED_MODO1, OUTPUT);
  pinMode(LED_MODO2, OUTPUT);
  pinMode(LED_MODO3, OUTPUT);
  Serial.begin(9600);
}
void verificarBotoes() {
  if (digitalRead(BTN_A) == LOW) { modoAtual = 1; delay(200); }
  if (digitalRead(BTN_B) == LOW) { modoAtual = 2; delay(200); }
  if (digitalRead(BTN_C) == LOW) { modoAtual = 3; delay(200); }
}
void atualizarIndicadores() {
  digitalWrite(LED_MODO1, modoAtual == 1 ? HIGH : LOW);
  digitalWrite(LED_MODO2, modoAtual == 2 ? HIGH : LOW);
  digitalWrite(LED_MODO3, modoAtual == 3 ? HIGH : LOW);
}
void modoManual() {
  int valorPot = analogRead(POT_PIN);
  int brilho = map(valorPot, 0, 1023, 0, 255);
  analogWrite(LED_MAIN, brilho);
  Serial.print("Modo 1 | Potenciometro: "); Serial.print(valorPot);
  Serial.print(" | PWM: "); Serial.println(brilho);
}
void modoAutomatico() {
  int valorLDR = analogRead(LDR_PIN);
  int brilho = map(valorLDR, 0, 1023, 255, 0);
  brilho = constrain(brilho, 0, 255);
  analogWrite(LED_MAIN, brilho);
  Serial.print("Modo 2 | LDR: "); Serial.print(valorLDR);
  Serial.print(" | PWM: "); Serial.println(brilho);
}
void modoFade() {
  brilhoFade += passoFade;
  if (brilhoFade >= 255) { brilhoFade = 255; passoFade = -passoFade; }
  if (brilhoFade <= 0) { brilhoFade = 0; passoFade = -passoFade; }
  analogWrite(LED_MAIN, brilhoFade);
  Serial.print("Modo 3 | Fade: "); Serial.println(brilhoFade);
  delay(15);
}
void loop() {
  verificarBotoes();
  atualizarIndicadores();
  switch (modoAtual) {
    case 1: modoManual(); break;
    case 2: modoAutomatico(); break;
    case 3: modoFade(); break;
  }
  delay(50);
}
