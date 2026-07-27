#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int PINO_LM35 = A0;
const float VREF = 5.0;
const float ADC_MAX = 1023.0;

float lerTemperatura() {
  int adc = analogRead(PINO_LM35);
  float tensao = adc * (VREF / ADC_MAX);
  return tensao * 100.0; // LM35: aproximadamente 10 mV por grau Celsius
}

void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Termometro UEG");
  delay(1500);
  lcd.clear();
}

void loop() {
  float temperatura = lerTemperatura();

  lcd.setCursor(0, 0);
  lcd.print("Temperatura:    ");

  lcd.setCursor(0, 1);
  lcd.print("                ");
  lcd.setCursor(0, 1);
  lcd.print(temperatura, 1);
  lcd.write((byte)223); // simbolo de grau no conjunto de caracteres do LCD
  lcd.print("C");

  delay(1000);
}
