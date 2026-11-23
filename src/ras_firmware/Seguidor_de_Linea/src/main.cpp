#include <Arduino.h>
#include "Control.h"
#include "Motor.h"
#include "Sensores.h"
#include "PID.h"
#include "Comunication.h"
#include "Seguidor_Linea.h"

//Control
Control control;

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

//PID
PID pid;
float Kp = 1.0;
float Ki = 0.0;
float Kd = 0.0;

void setup() {

  //Configuración de las variables de control
  Control_init(&control);

  //Configuración del wifi
  if(!Wifi_init()){
    Serial_print(0);
  } else {
    Serial_print(1);
  }

  //Configuración de los motores
  MotorA_init(&motores[0]);
  MotorB_init(&motores[1]);

  //Configuración de los sensores
  Sensores_init(&sensores, D2, D3, D4, D5, D6, D7);

  //Configuración del PID
  PID_init(&pid, Kp, Ki, Kd);

}

void loop() {

  if(digitalRead(STOP) == HIGH) {
    Control_setStby(&control, false);
    Control_setStart(&control, false);

    //Prueba de lectura de sensores
    Sensores_measure(&sensores);

  } else if(digitalRead(START) == HIGH) {
    Control_setStby(&control, true);
    Control_setStart(&control, true);
  }

  SeguidorLinea_init(&control, motores, &sensores, &pid);

}