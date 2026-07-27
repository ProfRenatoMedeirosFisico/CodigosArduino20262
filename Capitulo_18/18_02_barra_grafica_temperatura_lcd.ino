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
}

void loop() {
  float temperatura = lerTemperatura();

  int blocos = map(
    constrain((int)temperatura, 0, 40),
    0, 40,
    0, 16
  );

  lcd.setCursor(0, 0);
  lcd.print("                ");
  lcd.setCursor(0, 0);
  lcd.print("T=");
  lcd.print(temperatura, 1);
  lcd.write((byte)223);
  lcd.print("C");

  lcd.setCursor(0, 1);
  for (int i = 0; i < 16; i++) {
    if (i < blocos) {
      lcd.write((byte)255);
    } else {
      lcd.print(" ");
    }
  }

  delay(500);
}
