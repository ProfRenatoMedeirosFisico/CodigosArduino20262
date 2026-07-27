#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
char mensagem[] = "Fisica + Arduino";
void setup() {
  lcd.begin(16, 2);
  for (int i = 0; mensagem[i] != '\0'; i++) {
    lcd.print(mensagem[i]);
    delay(150);
  }
}

void loop() {
}
