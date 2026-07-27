#include <math.h>
const int PINO_NTC = A0;
const float R_FIXO = 10000.0;
const float R_NOMINAL = 10000.0;
const float T_NOMINAL = 25.0;
const float BETA = 3950.0;
void setup() {
  Serial.begin(9600);
  Serial.println("TERMOMETRO COM NTC");
}
void loop() {
  int leituraADC = analogRead(PINO_NTC);
  if (leituraADC <= 0) { Serial.println("Erro: leitura ADC igual a zero."); delay(1000); return; }
  float rNTC = R_FIXO * (1023.0 / leituraADC - 1.0);
  float tempK = 1.0 / ((1.0 / (T_NOMINAL + 273.15)) + (1.0 / BETA) * log(rNTC / R_NOMINAL));
  float tempC = tempK - 273.15;
  Serial.print("ADC: "); Serial.print(leituraADC);
  Serial.print(" | R_NTC: "); Serial.print(rNTC, 0);
  Serial.print(" ohms | Temperatura: "); Serial.print(tempC, 1); Serial.println(" C");
  delay(1000);
}
