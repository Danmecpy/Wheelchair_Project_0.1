#include <RHReliableDatagram.h>
#include <RH_ASK.h>
#include <SPI.h>

#define TX_ADDRESS 1
#define RX_ADDRESS 2

#define joystick_x A0
#define joystick_y A1

RH_ASK driver;
RHReliableDatagram gerente(driver, TX_ADDRESS);

uint8_t data[2];
// texte do github
void setup() {
  Serial.begin(9600);
  if (!gerente.init()) {
    Serial.println("Falha na inicializacao");
  }
}

void loop() {
  int direcao = analogRead(joystick_x);
  int velocidade = analogRead(joystick_y);

  direcao = map(direcao, 0, 1023, 0, 255);
  velocidade = map(velocidade, 0, 1023, 0, 255);

  data[0] = direcao;
  data[1] = velocidade;

  Serial.print("Enviando - Direção: ");
  Serial.print(direcao);
  Serial.print(" Velocidade: ");
  Serial.println(velocidade);

  if (!gerente.sendtoWait(data, sizeof(data), RX_ADDRESS)) {
    Serial.println("Falha no envio");
  }
  delay(100);
}
