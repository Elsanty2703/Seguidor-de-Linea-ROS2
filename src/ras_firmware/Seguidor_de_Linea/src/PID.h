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
    bool ready;
    float Kp;
    float Ki;
    float Kd;
    float Error;
    float lastError;
    int output;
};

void PID_init(PID* pid, float Kp, float Ki, float Kd);

void PID_setEnabled(PID* pid, bool value);
void PID_setReady(PID* pid, bool value);

bool PID_getEnabled(PID* pid);
bool PID_getReady(PID* pid);
int PID_getOutput(PID* pid);

void PID_calculate(PID* pid);

#endif // PID_H (Cierre de la guarda de inclusión)
