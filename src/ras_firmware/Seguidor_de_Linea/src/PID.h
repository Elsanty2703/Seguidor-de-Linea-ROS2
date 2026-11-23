#ifndef PID_H  // 1. Guarda de inclusión: evita que el archivo se compile dos veces
#define PID_H

#include <Arduino.h>
#include "Sensores.h"
#include "Comunication.h"

//PID
typedef enum {
    P, I, D
} PIDType;

struct PID {
    PIDType type;
    bool enabled;
    float Kp;
    float Ki;
    float Kd;
    float Error;
    float lastError;
    int output;
};

void PID_init(PID* pid, float Kp, float Ki, float Kd);

void PID_enable(PID* pid);
void PID_disable(PID* pid);

int PID_calculate(PID* pid, float measuredValue);

#endif // PID_H (Cierre de la guarda de inclusión)
