#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int contador = 0;
void setup() {
  lcd.begin(16, 2);
  lcd.print("Contador:");
}

void loop() {
  lcd.setCursor(0, 1);
  // Limpa a linha
  lcd.print("                ");
  lcd.setCursor(0, 1);
  lcd.print(contador);
  contador++;
  delay(500);
  if (contador > 99) {
    contador = 0;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Reiniciando...");
    delay(1000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Contador:");
  }
}
