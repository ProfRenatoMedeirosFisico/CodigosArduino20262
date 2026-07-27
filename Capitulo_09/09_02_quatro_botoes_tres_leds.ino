// ----------------------------
// Definicoes
// ----------------------------
const byte NUM_BOTOES = 4;
const byte NUM_LEDS    = 3;
const byte pinosBotoes[NUM_BOTOES] = {8, 9, 10, 11};
const byte pinosLeds[NUM_LEDS]      = {3, 4, 5};

// ----------------------------
// Configuracao
// ----------------------------

void setup() {
  Serial.begin(9600);
  // Configura os botoes
  for (byte i = 0; i < NUM_BOTOES; i++) {
    pinMode(pinosBotoes[i], INPUT_PULLUP);
  }
  // Configura os LEDs
  for (byte i = 0; i < NUM_LEDS; i++) {
    pinMode(pinosLeds[i], OUTPUT);
  }
}
// ----------------------------
// Programa principal
// ----------------------------

void loop() {
  byte pressionados = 0;
  // Conta quantos botoes estao pressionados
  for (byte i = 0; i < NUM_BOTOES; i++) {
    if (digitalRead(pinosBotoes[i]) == LOW) {
      pressionados++;
    }
  }
  // Primeiro apaga todos os LEDs
  for (byte i = 0; i < NUM_LEDS; i++) {
    digitalWrite(pinosLeds[i], LOW);
  }
  // Decide qual LED deve acender
  switch (pressionados) {
    case 1:
      digitalWrite(pinosLeds[0], HIGH);
      break;
    case 2:
      digitalWrite(pinosLeds[1], HIGH);
      break;
    case 3:
      digitalWrite(pinosLeds[2], HIGH);
      break;
    case 4:
      for (byte i = 0; i < NUM_LEDS; i++) {
        digitalWrite(pinosLeds[i], HIGH);
      }
      break;
  }
  // Exibe o resultado no Monitor Serial
  Serial.print("Botoes pressionados: ");
  Serial.println(pressionados);
  delay(100);
}
