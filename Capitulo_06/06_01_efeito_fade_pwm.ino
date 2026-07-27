// Fade - controle de brilho com PWM
#define LED_PIN 9  // DEVE ser um pino PWM: 3, 5, 6, 9, 10 ou 11

int brilho = 0;    // valor atual de brilho (0-255)
int passo = 5;     // incremento/decremento a cada ciclo

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  analogWrite(LED_PIN, brilho); // envia sinal PWM ao LED
  brilho += passo;   // aumenta ou diminui o brilho

  // Inverte a direcao quando atinge os limites
  if (brilho <= 0 || brilho >= 255) {
    passo = -passo;   // muda de +5 para -5 e vice-versa
  }
  delay(20); // pequena pausa para a animacao ser visivel
}
