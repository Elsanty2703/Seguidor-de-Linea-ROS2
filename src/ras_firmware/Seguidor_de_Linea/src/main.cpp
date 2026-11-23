#include <Arduino.h>
#include "Motor.h"
#include "PID.h"
#include "Comunication.h"

//Control
#define START 19
#define STOP 18
#define STBY 13

//PID
PID pid;
float Kp = 1.0;
float Ki = 0.0;
float Kd = 0.0;

//Motor
Motor motores[2];

//Sensores
Sensores sensores;
int D2 = -250;
int D3 = -150;
int D4 = -50;
int D5 = 50;
int D6 = 150;
int D7 = 250;

void setup() {
  //Configuración del wifi
  if(!Wifi_init()){
    exit(1);
  }

  //Configuración de los sensores
  Sensores_init(&sensores, D2, D3, D4, D5, D6, D7);

  //Configuración del PID
  PID_init(&pid, Kp, Ki, Kp);

  //Configuración de los motores
  MotorA_init(&motores[0]);
  MotorB_init(&motores[1]);

  //Configuración de los pines de control
  pinMode(STBY, OUTPUT);
  digitalWrite(STBY, LOW);
  pinMode(START, INPUT);
  pinMode(STOP, INPUT);
}

void loop() {

  if(digitalRead(START) == HIGH) {
    Motor_Start(&motores[0], 100);
    Motor_Start(&motores[1], 100);
  }

  if(digitalRead(STOP) == HIGH) {
    Motor_Stop(&motores[0]);
    Motor_Stop(&motores[1]);
  }

}