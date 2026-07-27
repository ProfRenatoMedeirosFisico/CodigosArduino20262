#include <Wire.h>

void setup() {
  Wire.begin();
  Serial.begin(9600);
  Serial.println("Scanner I2C");
  Serial.println("Procurando dispositivos...");
}

void loop() {
  byte erro;
  byte endereco;
  int encontrados = 0;
  for (endereco = 1; endereco < 127; endereco++) {
    Wire.beginTransmission(endereco);
    erro = Wire.endTransmission();
    if (erro == 0) {
      Serial.print("Dispositivo encontrado: 0x");
      if (endereco < 16) {
        Serial.print("0");
      }
      Serial.println(endereco, HEX);
      encontrados++;
    }
  }
  if (encontrados == 0) {
    Serial.println("Nenhum dispositivo encontrado.");
  }
  Serial.println("-----------------------------");
  delay(5000);
}
