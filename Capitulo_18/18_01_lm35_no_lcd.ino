#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int PINO_LM35 = A0;
float lerTemperatura() {
  int adc = analogRead(PINO_LM35);
  float tensao = adc * (5.0 / 1024.0);
  float temperatura = tensao * 100.0;
  return temperatura;
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
  lcd.print("Temperatura:");
  lcd.setCursor(0, 1);
  lcd.print(temperatura, 1);
  // Caractere 223 do LCD corresponde ao simbolo de grau
  lcd.write((byte)223);
  lcd.print("C   ");
  delay(1000);
}
