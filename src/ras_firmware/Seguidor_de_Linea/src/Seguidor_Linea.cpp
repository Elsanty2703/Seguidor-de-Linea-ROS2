#include "Seguidor_Linea.h"

void SeguidorLinea_init(Control* control, Motor* motores, Sensores* sensores, PID* pid) {
    
    if(!Control_getStart(control)) {
        Motor_Stop(&motores[0]);
        Motor_Stop(&motores[1]);
    } else if(Control_getTime(control)) {
        pid->Error = 0 - Sensores_measure(sensores);
        PID_setEnabled(pid, true);
        Control_setTime(control);
        
    }

    if (PID_getEnabled(pid)) {
        PID_calculate(pid);
    }

    if(PID_getReady(pid)) {
        // Ajustar la velocidad de los motores según la salida del PID
        int vel = Control_getVelBase(control);
        int pwmA = constrain(vel - PID_getOutput(pid), -255, 255); // Ajusta según tus necesidades
        int pwmB = constrain(vel + PID_getOutput(pid), -255, 255); // Ajusta según tus necesidades

        Motor_setPWM(&motores[0], pwmA);
        Motor_setPWM(&motores[1], pwmB);

        PID_setReady(pid, false);
        PID_setEnabled(pid, false);
    }
}