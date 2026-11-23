#ifndef MOTOR_H  // 1. Guarda de inclusión: evita que el archivo se compile dos veces
#define MOTOR_H

#include <Arduino.h>
#include "Comunication.h"

//Driver
#define AIN1 23
#define AIN2 22
#define PWMA 21
#define BIN1 17
#define BIN2 16
#define PWMB 4

//Motor
typedef enum {
    MOTOR_A,
    MOTOR_B
} MotorID;

struct Motor {
    MotorID id;
    int PWM;
};

void MotorA_init(Motor* motor);
void MotorB_init(Motor* motor);

void Motor_Stop(Motor* motor);

void Motor_setPWM(Motor* motor, int PWM);

#endif // MOTOR_H (Cierre de la guarda de inclusión)
