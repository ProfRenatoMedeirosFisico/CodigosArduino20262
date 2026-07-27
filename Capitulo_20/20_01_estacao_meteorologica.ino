#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include <math.h>

#define PINO_DHT 2
#define TIPO_DHT DHT11
DHT dht(PINO_DHT, TIPO_DHT);

// O endereco 0x27 e comum, mas deve ser confirmado com o scanner I2C.
LiquidCrystal_I2C lcd(0x27, 16, 2);

byte grau[8] = {
  B00110,
  B01001,
  B01001,
  B00110,
  B00000,
  B00000,
  B00000,
  B00000
};

float calcularOrvalho(float temperatura, float umidade) {
  if (umidade <= 0.0 || umidade > 100.0) {
    return NAN;
  }

  const float a = 17.27;
  const float b = 237.7;

  float alpha =
      (a * temperatura) / (b + temperatura)
      + log(umidade / 100.0);

  return (b * alpha) / (a - alpha);
}

void limparLinha(byte linha) {
  lcd.setCursor(0, linha);
  lcd.print("                ");  // 16 espacos
}

void exibirErro() {
  limparLinha(0);
  limparLinha(1);

  lcd.setCursor(1, 0);
  lcd.print("Erro no DHT11");

  lcd.setCursor(0, 1);
  lcd.print("Verifique sensor");
}

void exibirDados(float temperatura,
                 float umidade,
                 float indiceCalor,
                 float orvalho) {
  limparLinha(0);
  limparLinha(1);

  // Linha 1: T:25.0° UR:60%
  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.print(temperatura, 1);
  lcd.write(byte(0));
  lcd.print(" UR:");
  lcd.print((int)umidade);
  lcd.print("%");

  // Linha 2: IC:25.5° O:16.7°
  lcd.setCursor(0, 1);
  lcd.print("IC:");
  lcd.print(indiceCalor, 1);
  lcd.write(byte(0));
  lcd.print(" O:");
  lcd.print(orvalho, 1);
  lcd.write(byte(0));
}

void setup() {
  lcd.init();
  lcd.backlight();

  dht.begin();
  lcd.createChar(0, grau);

  lcd.setCursor(0, 0);
  lcd.print("  Estacao UEG   ");
  lcd.setCursor(0, 1);
  lcd.print(" Inicializando  ");

  delay(2000);
  lcd.clear();
}

void loop() {
  float umidade = dht.readHumidity();
  float temperatura = dht.readTemperature();

  if (isnan(umidade) || isnan(temperatura)) {
    exibirErro();
    delay(2500);
    return;
  }

  float indiceCalor =
      dht.computeHeatIndex(temperatura, umidade, false);

  float orvalho = calcularOrvalho(temperatura, umidade);

  if (isnan(orvalho)) {
    exibirErro();
    delay(2500);
    return;
  }

  exibirDados(temperatura,
              umidade,
              indiceCalor,
              orvalho);

  // O DHT11 nao deve ser lido em intervalos muito curtos.
  delay(2500);
}
