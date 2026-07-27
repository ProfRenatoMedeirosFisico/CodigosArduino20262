// Robo esquivador de obstaculos
// Arduino Uno + HC-SR04 + L298N
// --------------------------------------------------
// Pinos do L298N
// --------------------------------------------------
#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11
#define ENA 5
#define ENB 6
// --------------------------------------------------
// Sensor HC-SR04
// --------------------------------------------------
#define TRIG 12
#define ECHO 13
// --------------------------------------------------
// Parametros do robo
// --------------------------------------------------
#define DIST_MIN    20
#define VEL_NORMAL  180
#define VEL_RECUO   150
#define VEL_GIRO    160

void setup() {
  // Saidas do L298N
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  // Sensor ultrassonico
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  // Garante que o trigger comece em LOW
  digitalWrite(TRIG, LOW);
  Serial.begin(9600);
  parar();
}
// --------------------------------------------------
// Mede a distancia com o HC-SR04
// --------------------------------------------------
float medirDistancia() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  // Aguarda o eco por no maximo 25 ms
  unsigned long tempo = pulseIn(ECHO, HIGH, 25000UL);
  // Se nenhum eco for recebido,
  // considera o caminho livre
  if (tempo == 0) {
    return 999.0;
  }
  // Velocidade aproximada do som:
  // 0,0343 cm por microssegundo
  float distancia = tempo * 0.0343 / 2.0;
  return distancia;
}
// --------------------------------------------------
// Movimento para frente
// --------------------------------------------------

void frente(int velocidade) {
  analogWrite(ENA, velocidade);
  analogWrite(ENB, velocidade);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
// --------------------------------------------------
// Movimento para tras
// --------------------------------------------------
void recuar(int velocidade) {
  analogWrite(ENA, velocidade);
  analogWrite(ENB, velocidade);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
// --------------------------------------------------
// Giro para a direita
// --------------------------------------------------

void girarDireita(int velocidade) {
  analogWrite(ENA, velocidade);
  analogWrite(ENB, velocidade);
  // Motor A para frente
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  // Motor B para tras
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
// --------------------------------------------------
// Para os dois motores
// --------------------------------------------------

void parar() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
// --------------------------------------------------
// Programa principal
// --------------------------------------------------

void loop() {
  float distancia = medirDistancia();
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");
  // Obstaculo detectado
  if (distancia < DIST_MIN) {
    parar();
    delay(300);
    recuar(VEL_RECUO);
    delay(600);
    parar();
    delay(150);
    girarDireita(VEL_GIRO);
    delay(450);
    parar();
    delay(150);
  }
  // Caminho livre
  else {
    frente(VEL_NORMAL);
  }
  delay(50);
}
