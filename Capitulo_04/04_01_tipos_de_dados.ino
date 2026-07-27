// Constante: nao pode ser alterada durante o programa
const int ledPin = 13;    // pino do LED - constante inteira
#define INTERVALO 500     // outra forma de definir constantes

// Variaveis: podem mudar durante a execucao
int contador = 0;         // variavel inteira, iniciada em zero
float temperatura = 25.5; // variavel decimal
bool ligado = false;      // variavel logica (true/false)
String mensagem = "Ola!"; // cadeia de texto

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600); // inicia comunicacao serial a 9600 bits/s
}

void loop() {
  contador++;           // incrementa (equivale a contador = contador + 1)
  Serial.print("Contagem: ");
  Serial.println(contador); // println pula linha apos imprimir
  delay(INTERVALO);
}
