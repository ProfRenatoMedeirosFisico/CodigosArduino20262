// ============================================================
// Controle de dois motores CC com modulo L298N
// Velocidade: potenciometro
// Direcao: botao
// Liga/desliga: botao
// ============================================================
// ---------- L298N ----------
const byte ENA = 5;   // PWM - Motor A
const byte IN1 = 8;
const byte IN2 = 9;
const byte ENB = 6;   // PWM - Motor B
const byte IN3 = 10;
const byte IN4 = 11;
// ---------- Entradas ----------
const byte BTN_DIRECAO = 7;
const byte BTN_LIGA    = 4;
const byte POT_VEL     = A0;
// ---------- Indicador ----------
const byte LED_STATUS = 3;
// ---------- Estados ----------
bool sentidoDireto = true;
bool motoresLigados = false;
bool ultimoBtnDirecao = HIGH;
bool ultimoBtnLiga    = HIGH;
// ============================================================
// Configura o sentido de rotacao
// ============================================================

void definirSentido(bool direto) {
  if (direto) {
    // Motor A
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    // Motor B
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  } else {
    // Motor A
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    // Motor B
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
  }
}
// ============================================================
// Aciona os motores
// ============================================================

void moverMotores(int velocidade) {
  definirSentido(sentidoDireto);
  analogWrite(ENA, velocidade);
  analogWrite(ENB, velocidade);
}
// ============================================================
// Desabilita as duas pontes
// ============================================================

void pararMotores() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}
// ============================================================
// SETUP
// ============================================================
void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(BTN_DIRECAO, INPUT_PULLUP);
  pinMode(BTN_LIGA, INPUT_PULLUP);
  pinMode(LED_STATUS, OUTPUT);
  // Inicialmente os motores permanecem desligados
  pararMotores();
  Serial.begin(9600);
  Serial.println("================================");
  Serial.println(" Controle de Motores com L298N ");
  Serial.println("================================");
}
// ============================================================
// LOOP
// ============================================================

void loop() {
  // ----------------------------------------------------------
  // Leitura dos botoes
  // ----------------------------------------------------------
  bool btnDirecao = digitalRead(BTN_DIRECAO);
  bool btnLiga    = digitalRead(BTN_LIGA);
  // ----------------------------------------------------------
  // Botao de direcao
  // Detecta apenas HIGH -> LOW
  // ----------------------------------------------------------
  if (ultimoBtnDirecao == HIGH &&
      btnDirecao == LOW) {
    sentidoDireto = !sentidoDireto;
    delay(40); // debounce simples
  }
  ultimoBtnDirecao = btnDirecao;
  // ----------------------------------------------------------
  // Botao liga/desliga
  // ----------------------------------------------------------
  if (ultimoBtnLiga == HIGH &&
      btnLiga == LOW) {
    motoresLigados = !motoresLigados;
    delay(40); // debounce simples
  }
  ultimoBtnLiga = btnLiga;
  // ----------------------------------------------------------
  // Potenciometro
  // ----------------------------------------------------------
  int leituraPot = analogRead(POT_VEL);
  int velocidade = map(
    leituraPot,
    0, 1023,
    0, 255
  );
  // ----------------------------------------------------------
  // Controle dos motores
  // ----------------------------------------------------------
  if (motoresLigados) {
    moverMotores(velocidade);
    digitalWrite(LED_STATUS, HIGH);
  } else {
    pararMotores();
    digitalWrite(LED_STATUS, LOW);
  }
  // ----------------------------------------------------------
  // Monitor Serial
  // ----------------------------------------------------------
  Serial.print("Estado: ");
  if (motoresLigados) {
    Serial.print("LIGADO");
  } else {
    Serial.print("PARADO");
  }
  Serial.print(" | PWM: ");
  Serial.print(velocidade);
  Serial.print(" | Sentido: ");
  if (sentidoDireto) {
    Serial.println("DIRETO");
  } else {
    Serial.println("INVERSO");
  }
  delay(100);
}
