const int PINO_LM35 = A0;
const int PINO_LED = 8;
const int PINO_BUZZER = 7;
const float TEMP_ALARME = 35.0;
void setup() {
  pinMode(PINO_LED, OUTPUT);
  pinMode(PINO_BUZZER, OUTPUT);
  Serial.begin(9600);
}
float lerTemperatura() {
  int leituraADC = analogRead(PINO_LM35);
  float tensao = leituraADC * (5.0 / 1023.0);
  return tensao * 100.0;
}
void soarAlarme() {
  tone(PINO_BUZZER, 1000); delay(200); noTone(PINO_BUZZER); delay(100);
}
void loop() {
  float temperatura = lerTemperatura();
  Serial.print("Temperatura: "); Serial.print(temperatura, 1); Serial.println(" graus C");
  if (temperatura >= TEMP_ALARME) {
    digitalWrite(PINO_LED, HIGH); soarAlarme();
    Serial.println("*** ALERTA: TEMPERATURA ELEVADA ***");
  } else {
    digitalWrite(PINO_LED, LOW); noTone(PINO_BUZZER);
  }
  delay(1000);
}
