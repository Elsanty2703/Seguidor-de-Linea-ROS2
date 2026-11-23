#include "Motor.h"

void MotorA_init(Motor* motor) {

    pinMode(AIN1, OUTPUT);
    digitalWrite(AIN1, LOW);
    pinMode(AIN2, OUTPUT);
    digitalWrite(AIN2, LOW);
    ledcSetup(0, 20000, 8);
    ledcAttachPin(PWMA, 0);
    ledcWrite(0, 0);

    motor->id = MOTOR_A;
    motor->PWM = 0;
}

void MotorB_init(Motor* motor) {

    pinMode(BIN1, OUTPUT);
    digitalWrite(BIN1, LOW);
    pinMode(BIN2, OUTPUT);
    digitalWrite(BIN2, LOW);
    ledcSetup(1, 20000, 8);
    ledcAttachPin(PWMB, 1);
    ledcWrite(1, 0);

    motor->id = MOTOR_B;
    motor->PWM = 0;
}

void Motor_Stop(Motor* motor) {
    motor->PWM = 0;
    if (motor->id == MOTOR_A) {
        digitalWrite(AIN1, HIGH);
        digitalWrite(AIN2, HIGH);
        ledcWrite(0, 0);
    } else if (motor->id == MOTOR_B) {
        digitalWrite(BIN1, HIGH);
        digitalWrite(BIN2, HIGH);
        ledcWrite(1, 0);
    }
}

void Motor_setPWM(Motor* motor, int PWM) {
    motor->PWM = PWM;

    if (motor->id == MOTOR_A) {
        if(PWM >= 0){
            digitalWrite(AIN1, HIGH);
            digitalWrite(AIN2, LOW);
        } else if(PWM < 0){
            digitalWrite(AIN1, LOW);
            digitalWrite(AIN2, HIGH);
            PWM = -PWM; // Convertir a positivo para el duty cycle
        }
        ledcWrite(0, PWM);

    } else if (motor->id == MOTOR_B) {
        if(PWM >= 0){
            digitalWrite(BIN1, LOW);
            digitalWrite(BIN2, HIGH);
        } else if(PWM < 0){
            digitalWrite(BIN1, HIGH);
            digitalWrite(BIN2, LOW);
            PWM = -PWM; // Convertir a positivo para el duty cycle
        }
        ledcWrite(1, PWM);
    }
}
