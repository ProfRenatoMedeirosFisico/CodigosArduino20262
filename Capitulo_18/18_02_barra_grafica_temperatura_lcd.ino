#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int PINO_LM35 = A0;
float lerTemperatura() {
  int adc = analogRead(PINO_LM35);
  float tensao = adc * (5.0 / 1024.0);
  return tensao * 100.0;
}

void loop() {
  float temperatura = lerTemperatura();
  int blocos = map(
      constrain((int)temperatura, 0, 40),
      0,
      40,
      0,
      16
  );
  lcd.setCursor(0, 0);
  lcd.print("T=");
  lcd.print(temperatura, 1);
  lcd.write((byte)223);
  lcd.print("C    ");
  lcd.setCursor(0, 1);
  for (int i = 0; i < 16; i++) {
    if (i < blocos) {
      lcd.write((byte)255);
    }
    else {
      lcd.print(" ");
    }
  }
  delay(500);
}

void setup() {
  lcd.begin(16, 2);
}
