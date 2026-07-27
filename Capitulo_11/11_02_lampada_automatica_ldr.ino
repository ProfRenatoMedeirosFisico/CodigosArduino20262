// ============================================================
// Sensor LDR - Lampada automatica
// ============================================================

#define PINO_LDR A0
#define PINO_LED 9
// Valor obtido experimentalmente
#define LIMIAR 300

void setup() {
  pinMode(PINO_LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Leitura do conversor analogico
  int leitura = analogRead(PINO_LDR);
  // Conversao aproximada para tensao
  float tensao = leitura * (5.0 / 1023.0);
  // Mostra os valores no Monitor Serial
  Serial.print("ADC: ");
  Serial.print(leitura);
  Serial.print(" | Tensao: ");
  Serial.print(tensao, 2);
  Serial.print(" V");
  if (leitura < LIMIAR) {
    digitalWrite(PINO_LED, HIGH);
    Serial.println(" | LED: LIGADO (escuro)");
  }
  else {
    digitalWrite(PINO_LED, LOW);
    Serial.println(" | LED: DESLIGADO (claro)");
  }
  delay(500);
}
