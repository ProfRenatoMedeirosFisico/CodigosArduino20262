#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
byte setaCima[8] = {
  B00100,
  B01110,
  B10101,
  B00100,
  B00100,
  B00100,
  B00100,
  B00000
};

void setup() {
  lcd.begin(16, 2);
  lcd.createChar(0, setaCima);
  lcd.setCursor(0, 0);
  lcd.print("Temperatura");
  lcd.setCursor(0, 1);
  lcd.write((byte)0);
  lcd.print(" aumentando");
}

void loop() {
}
