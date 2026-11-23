#ifndef SENSORES_H  // 1. Guarda de inclusión: evita que el archivo se compile dos veces
#define SENSORES_H

#include <Arduino.h>
#include "Comunication.h"

//Sensores IR
#define IR_D2 33
#define IR_D3 32
#define IR_D4 35
#define IR_D5 34
#define IR_D6 39
#define IR_D7 36

struct Sensores {
    int sensorValues[6];
    int sensorWeights[6];
    float measuredValue;
};

void Sensores_init(Sensores* sensores, int D2, int D3, int D4, int D5, int D6, int D7);

float Sensores_measure(Sensores* sensores);

#endif // SENSORES_H (Cierre de la guarda de inclusión)
