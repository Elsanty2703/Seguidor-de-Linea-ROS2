#include "PID.h"

void PID_init(PID* pid, float Kp, float Ki, float Kd) {
    
    pid->type = P;
    pid->enabled = false;

    pid->Kp = Kp;
    pid->Ki = Ki;
    pid->Kd = Kd;

    pid->Error = 0;
    pid->lastError = 0;
    pid->output = 0;
}

void PID_enable(PID* pid) {
    pid->enabled = true;
}

void PID_disable(PID* pid) {
    pid->enabled = false;
}