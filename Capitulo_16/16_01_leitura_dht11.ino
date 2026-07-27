// =====================================================
// Sensor DHT11 - temperatura e umidade
// =====================================================
#include <DHT.h>
#define PINO_DHT 2
#define TIPO_DHT DHT11
DHT dht(PINO_DHT, TIPO_DHT);

void setup() {
  Serial.begin(9600);
  dht.begin();
  Serial.println("================================");
  Serial.println("       SENSOR DHT11");
  Serial.println("================================");
  Serial.println();
}

void loop() {
  float umidade = dht.readHumidity();
  float temperatura = dht.readTemperature();
  if (isnan(umidade) || isnan(temperatura)) {
    Serial.println("Erro ao ler o DHT11!");
    delay(2000);
    return;
  }
  Serial.print("Temperatura: ");
  Serial.print(temperatura, 1);
  Serial.println(" C");
  Serial.print("Umidade:     ");
  Serial.print(umidade, 1);
  Serial.println(" %");
  Serial.println("----------------------------");
  delay(2000);
}
