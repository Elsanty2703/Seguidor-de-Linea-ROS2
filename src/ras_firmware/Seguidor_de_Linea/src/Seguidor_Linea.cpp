#include "Seguidor_Linea.h"

void SeguidorLinea_init(Control* control, Motor* motores, Sensores* sensores, PID* pid) {
    if(Control_getStart(control) && Control_getStby(control)) {
        // Leer los valores de los sensores y retornar el error
        float error = 0 - Sensores_measure(sensores); // Suponiendo que el valor deseado es 0

        // Calcular la salida del PID
        float pidOutput = PID_calculate(pid, error);

        // Ajustar la velocidad de los motores según la salida del PID
        int pwmA = constrain(pidOutput, -255, 255); // Ajusta según tus necesidades
        int pwmB = constrain(pidOutput, -255, 255); // Ajusta según tus necesidades

        Motor_setPWM(&motores[0], pwmA);
        Motor_setPWM(&motores[1], pwmB);
    } else {
        Motor_Stop(&motores[0]);
        Motor_Stop(&motores[1]);
    }
}