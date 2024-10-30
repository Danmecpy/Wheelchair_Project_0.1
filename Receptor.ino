#include <RHReliableDatagram.h>
#include <RH_ASK.h>
#include <SPI.h>

#define TX_ADDRESS 1
#define RX_ADDRESS 2

#define motor1_rpwm 10
#define motor1_lpwm 9
#define motor1_re 6
#define motor1_le 7

#define motor2_rpwm 5
#define motor2_lpwm 4
#define motor2_re 3
#define motor2_le 2

RH_ASK driver;
RHReliableDatagram gerente(driver, RX_ADDRESS);
// texto de teste para github
// segundo texte de github
uint8_t buf[2];
uint8_t tamanho = sizeof(buf);

void setup() {
  Serial.begin(9600);
  if (!gerente.init()) {
    Serial.println("Falha na inicializacao");
  }

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
  if (gerente.available()) {
    if (gerente.recvfromAck(buf, &tamanho)) {
      int direcao = buf[0];
      int velocidade = buf[1];

      Serial.print("Recebido - Direção: ");
      Serial.print(direcao);
      Serial.print(" Velocidade: ");
      Serial.println(velocidade);

      if (direcao > 128) {
        moverFrente(velocidade);
      } else if (direcao < 128) {
        moverTras(velocidade);
      } else {
        pararMotores();
      }
    }
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
  analogWrite(motor1_lpwm, velocidade);
  digitalWrite(motor1_rpwm, LOW);
  digitalWrite(motor1_le, HIGH);
  digitalWrite(motor1_re,HIGH);

  analogWrite(motor2_lpwm, velocidade);
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
