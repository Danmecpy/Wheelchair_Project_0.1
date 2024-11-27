

#define b_frente 5
#define b_tras 4
#define b_direita 12
#define b_esquerda 7pinMode(b_parar,INPUT);
#define b_parar 0

#define motor1_rpwm 11
#define motor1_lpwm 10
#define motor1_re 1
#define motor1_le 2

#define motor2_rpwm 3
#define motor2_lpwm 6
#define motor2_re 9
#define motor2_le 8

void setup() {

  Serial.begin(9600);


  pinMode(motor1_rpwm, OUTPUT);
  pinMode(motor1_lpwm, OUTPUT);
  pinMode(motor1_re, OUTPUT);
  pinMode(motor1_le, OUTPUT);

  pinMode(motor2_rpwm, OUTPUT);
  pinMode(motor2_lpwm, OUTPUT);
  pinMode(motor2_re, OUTPUT);
  pinMode(motor2_le, OUTPUT);

  pinMode(b_frente,INPUT);
  pinMode(b_tras,INPUT);
  pinMode(b_direita,INPUT);
  pinMode(b_esquerda,INPUT);
  pinMode(b_parar,INPUT);

  digitalWrite(b_frente,HIGH);
  digitalWrite(b_tras,HIGH);
  digitalWrite(b_direita,HIGH);
  digitalWrite(b_esquerda,HIGH);
  digitalWrite(b_parar,HIGH);
  
  pararMotores();

  
}


void loop() {
  
  int frente = digitalRead(b_frente);
  int tras = digitalRead(b_tras);
  int direita = digitalRead(b_direita);
  int esquerda = digitalRead(b_esquerda);

  //Serial.println(frente); // azul do lado esquerdo
  //Serial.println(tras); // branco do lado esquerdo
  //Serial.println(direita); // azul do lado direito
  //Serial.println(esquerda); // branco do lado direito
  
  if (frente==0){
    moverFrente(80);
  }

  else if (tras==0){
    moverTras(80);
  }

  else if (direita==0){
    moverDireita(80);
  }

  else if (esquerda==0){
    moverEsquerda(80);
  }
  else if (digitalRead(b_parar)==0){
    pararMotores();
  }
  else {
    pararMotores();
  }
  delay(100);



 }

// mover para frente 
void moverFrente(int velocidade) {
  analogWrite(motor1_rpwm, LOW);
  analogWrite(motor1_lpwm, velocidade);
  digitalWrite(motor1_re, HIGH);
  digitalWrite(motor1_le, HIGH);

  analogWrite(motor2_rpwm,LOW);
  analogWrite(motor2_lpwm,velocidade);
  digitalWrite(motor2_re, HIGH);
  digitalWrite(motor2_le,HIGH);
}

//mover para tras 
void moverTras(int velocidade) {
  analogWrite(motor1_rpwm, velocidade);
  analogWrite(motor1_lpwm, LOW);
  digitalWrite(motor1_le, HIGH);
  digitalWrite(motor1_re,HIGH);

  analogWrite(motor2_rpwm,velocidade);
  analogWrite(motor2_lpwm, LOW);
  digitalWrite(motor2_le, HIGH);
  digitalWrite(motor2_re, HIGH);
}
// MOTOR 1 DIREITA , MOTOR 2 ESQUERDA

void moverEsquerda(int velocidade) {
  analogWrite(motor1_rpwm, LOW);
  analogWrite(motor1_lpwm, velocidade);
  digitalWrite(motor1_le, HIGH);
  digitalWrite(motor1_re,HIGH);

  analogWrite(motor2_rpwm,velocidade);
  digitalWrite(motor2_lpwm, LOW);
  digitalWrite(motor2_le, HIGH);
  digitalWrite(motor2_re, HIGH);
}

void moverDireita(int velocidade){
  analogWrite(motor1_rpwm, velocidade);
  analogWrite(motor1_lpwm, LOW);
  digitalWrite(motor1_le, HIGH);
  digitalWrite(motor1_re,HIGH);

  analogWrite(motor2_rpwm,LOW);
  analogWrite(motor2_lpwm, velocidade);
  digitalWrite(motor2_le, HIGH);
  digitalWrite(motor2_re, HIGH);

}

void pararMotores() {
  digitalWrite(motor1_rpwm, LOW);
  digitalWrite(motor1_lpwm, LOW);
  digitalWrite(motor1_re, LOW);
  digitalWrite(motor1_le, LOW);

  digitalWrite(motor2_rpwm, LOW);
  digitalWrite(motor2_lpwm, LOW);
  digitalWrite(motor2_re, LOW);
  digitalWrite(motor2_le, LOW);
}