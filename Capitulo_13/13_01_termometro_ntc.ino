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

  // Com a montagem da apostila (NTC em 5 V e resistor fixo em GND),
  // os extremos 0 e 1023 tornam o calculo da resistencia indefinido.
  if (leituraADC <= 0 || leituraADC >= 1023) {
    Serial.println("Erro: leitura ADC no limite da escala. Verifique o sensor e as conexoes.");
    delay(1000);
    return;
  }

  float rNTC = R_FIXO * (1023.0 / leituraADC - 1.0);

  float tempK = 1.0 / (
    (1.0 / (T_NOMINAL + 273.15))
    + (1.0 / BETA) * log(rNTC / R_NOMINAL)
  );

  float tempC = tempK - 273.15;

  Serial.print("ADC: ");
  Serial.print(leituraADC);
  Serial.print(" | R_NTC: ");
  Serial.print(rNTC, 0);
  Serial.print(" ohms | Temperatura: ");
  Serial.print(tempC, 1);
  Serial.println(" C");

  delay(1000);
}
