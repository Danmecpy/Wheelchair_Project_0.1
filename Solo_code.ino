

#define joystick_x A0
#define joystick_y A2

#define motor1_rpwm 10
#define motor1_lpwm 9
#define motor1_re 6
#define motor1_le 7

#define motor2_rpwm 5
#define motor2_lpwm 4
#define motor2_re 3
#define motor2_le 2

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
}


void loop() {
  int direcao = analogRead(joystick_x);
  int velocidade = analogRead(joystick_y);

  direcao = map(direcao, 0, 1023, 0, 255);
  velocidade = map(velocidade, 0, 1023, 0, 255);

  Serial.print("Enviando - Direção: ");
  Serial.print(direcao);
  Serial.print(" Velocidade: ");
  Serial.println(velocidade);

  if (direcao>132 && velocidade == 131 ){
    moverFrente(direcao);
  }
  else if (direcao<129 && velocidade == 131 ){
    moverTras(direcao);
  }
  else if (direcao ==130 && velocidade <131){
    moverDireita(velocidade+130);
  }
  else if (direcao == 130 && velocidade >131){
    moverEsquerda(velocidade-130);
  }
  else {
    pararMotores();
  }


 }

void moverFrente(int velocidade) {
  analogWrite(motor1_rpwm, velocidade);
  digitalWrite(motor1_lpwm, LOW);
  digitalWrite(motor1_re, HIGH);
  digitalWrite(motor1_le, HIGH);

  analogWrite(motor2_rpwm, velocidade);
  digitalWrite(motor2_lpwm, LOW);
  digitalWrite(motor2_re, HIGH);
  digitalWrite(motor2_le,HIGH);
}

void moverTras(int velocidade) {
  analogWrite(motor1_lpwm, velocidade+255);
  digitalWrite(motor1_rpwm, LOW);
  digitalWrite(motor1_le, HIGH);
  digitalWrite(motor1_re,HIGH);

  analogWrite(motor2_lpwm, velocidade+255);
  digitalWrite(motor2_rpwm, LOW);
  digitalWrite(motor2_le, HIGH);
  digitalWrite(motor2_re, HIGH);
}
// MOTOR 1 DIREITA , MOTOR 2 ESQUERDA

void moverDireita(int velocidade) {
  analogWrite(motor1_lpwm, velocidade);
  digitalWrite(motor1_rpwm, LOW);
  digitalWrite(motor1_le, HIGH);
  digitalWrite(motor1_re,HIGH);

  analogWrite(motor2_lpwm,LOW );
  digitalWrite(motor2_rpwm, LOW);
  digitalWrite(motor2_le, HIGH);
  digitalWrite(motor2_re, HIGH);
}

void moverEsquerda(int velocidade){
 analogWrite(motor1_lpwm, LOW);
  digitalWrite(motor1_rpwm, LOW);
  digitalWrite(motor1_le, HIGH);
  digitalWrite(motor1_re,HIGH);

  analogWrite(motor2_lpwm,velocidade );
  digitalWrite(motor2_rpwm, LOW);
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
