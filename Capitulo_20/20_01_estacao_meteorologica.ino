// =============================================
// Estacao Meteorologica
// DHT11 + LCD 16x2 I2C
// =============================================
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
// ------------------------------------------------
// Configuracao do DHT11
// ------------------------------------------------
#define PINO_DHT 2
#define TIPO_DHT DHT11
DHT dht(PINO_DHT, TIPO_DHT);
// ------------------------------------------------
// Configuracao do LCD
// Endereco mais comum: 0x27
// ------------------------------------------------
LiquidCrystal_I2C lcd(0x27, 16, 2);
// ------------------------------------------------
// Caracter personalizado: simbolo de grau
// ------------------------------------------------
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
// =============================================
// FUNCAO: calcular ponto de orvalho
// =============================================
float calcularOrvalho(float temperatura, float umidade) {
  // Evita logaritmo de zero ou valor invalido
  if (umidade <= 0.0) {
    return NAN;
  }
  const float a = 17.27;
  const float b = 237.7;
  float alpha =
      (a * temperatura) / (b + temperatura)
      + log(umidade / 100.0);
  float orvalho =
      (b * alpha) / (a - alpha);
  return orvalho;
}
// =============================================
// FUNCAO: exibir erro
// =============================================

void exibirErro() {
  lcd.setCursor(0, 0);
  lcd.print(" Erro no DHT11  ");
  lcd.setCursor(0, 1);
  lcd.print("Verifique sensor");
}
// =============================================
// FUNCAO: exibir dados
// =============================================

void exibirDados(float temperatura,
                 float umidade,
                 float indiceCalor,
                 float orvalho) {
  // ------------------------------------------------
  // Linha 1
  // T:25.0 C UR:60%
  // ------------------------------------------------
  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.print(temperatura, 1);
  lcd.write(byte(0));
  lcd.print("C ");
  lcd.print("UR:");
  lcd.print((int)umidade);
  lcd.print("%");
  // Apaga caracteres residuais
  lcd.print("  ");
  // ------------------------------------------------
  // Linha 2
  // IC:25.5 O:16.7
  // ------------------------------------------------
  lcd.setCursor(0, 1);
  lcd.print("IC:");
  lcd.print(indiceCalor, 1);
  lcd.write(byte(0));
  lcd.print(" O:");
  lcd.print(orvalho, 1);
  lcd.write(byte(0));
  // Apaga caracteres residuais
  lcd.print(" ");
}
// =============================================
// SETUP
// =============================================

void setup() {
  // Inicializa LCD
  lcd.init();
  lcd.backlight();
  // Inicializa DHT11
  dht.begin();
  // Registra o simbolo de grau na memoria 0
  lcd.createChar(0, grau);
  // ------------------------------------------------
  // Tela inicial
  // ------------------------------------------------
  lcd.setCursor(0, 0);
  lcd.print("  Estacao UEG   ");
  lcd.setCursor(0, 1);
  lcd.print(" Inicializando  ");
  delay(2000);
  lcd.clear();
}
// =============================================
// LOOP PRINCIPAL
// =============================================

void loop() {
  // ------------------------------------------------
  // 1. Realiza as medicoes
  // ------------------------------------------------
  float umidade =
      dht.readHumidity();
  float temperatura =
      dht.readTemperature();
  // ------------------------------------------------
  // 2. Verifica se a leitura foi valida
  // ------------------------------------------------
  if (isnan(umidade) ||
      isnan(temperatura)) {
    exibirErro();
    delay(2500);
    return;
  }
  // ------------------------------------------------
  // 3. Calcula as grandezas derivadas
  // ------------------------------------------------
  float indiceCalor =
      dht.computeHeatIndex(
          temperatura,
          umidade,
          false
      );
  float orvalho =
      calcularOrvalho(
          temperatura,
          umidade
      );
  // ------------------------------------------------
  // 4. Atualiza o LCD
  // ------------------------------------------------
  exibirDados(
      temperatura,
      umidade,
      indiceCalor,
      orvalho
  );
  // ------------------------------------------------
  // 5. Aguarda antes da proxima leitura
  // ------------------------------------------------
  delay(2500);
}
