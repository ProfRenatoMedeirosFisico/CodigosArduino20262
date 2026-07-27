#include <DHT.h>
#define PINO_DHT 2
#define TIPO_DHT DHT11
DHT dht(PINO_DHT, TIPO_DHT);

void setup() {
  Serial.begin(9600);
  dht.begin();
  Serial.println("Temp (C) | Umidade (%) | Indice de calor (C)");
  Serial.println("---------------------------------------------");
}

void loop() {
  float umidade = dht.readHumidity();
  float temperatura = dht.readTemperature();
  if (isnan(umidade) || isnan(temperatura)) {
    Serial.println("Erro ao ler o sensor DHT11!");
    delay(2000);
    return;
  }
  float indiceCalor = dht.computeHeatIndex(temperatura, umidade, false);
  Serial.print(temperatura, 1);
  Serial.print("      | ");
  Serial.print(umidade, 1);
  Serial.print("        | ");
  Serial.println(indiceCalor, 1);
  delay(2000);
}
