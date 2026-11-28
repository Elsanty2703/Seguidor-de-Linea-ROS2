#include "PID.h"

void PID_init(PID* pid, float Kp, float Ki, float Kd) {
    
    pid->type = P;
    pid->enabled = false;
    pid->ready = false;

    pid->Kp = Kp;
    pid->Ki = Ki;
    pid->Kd = Kd;

    pid->Error = 0;
    pid->lastError = 0;
    pid->output = 0;
}

void PID_setEnabled(PID* pid, bool value) {
    pid->enabled = value;
}

void PID_setReady(PID* pid, bool value) {
    pid->ready = value;
}

bool PID_getEnabled(PID* pid) {
    return pid->enabled;
}

bool PID_getReady(PID* pid) {
    return pid->ready;
}

int PID_getOutput(PID* pid) {
    return pid->output;
}

void PID_calculate(PID* pid) {
    //calculo del PID con maquina de estados finitos
    pid->output = 0;
    pid->ready = true;
}