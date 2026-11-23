#include "Sensores.h"

void Sensores_init(Sensores* sensores, int D2, int D3, int D4, int D5, int D6, int D7) {

    pinMode(IR_D2, INPUT);
    pinMode(IR_D3, INPUT);
    pinMode(IR_D4, INPUT);
    pinMode(IR_D5, INPUT);
    pinMode(IR_D6, INPUT);
    pinMode(IR_D7, INPUT);
    analogReadResolution(12);

    sensores->sensorValues[0] = 0;
    sensores->sensorValues[1] = 0;
    sensores->sensorValues[2] = 0;
    sensores->sensorValues[3] = 0;
    sensores->sensorValues[4] = 0;
    sensores->sensorValues[5] = 0;

    sensores->sensorWeights[0] = D2;
    sensores->sensorWeights[1] = D3;
    sensores->sensorWeights[2] = D4;
    sensores->sensorWeights[3] = D5;
    sensores->sensorWeights[4] = D6;
    sensores->sensorWeights[5] = D7;

    sensores->measuredValue = 0.0;
}

float Sensores_measure(Sensores* sensores) {
    // Lectura de los valores de los sensores
    sensores->sensorValues[0] = analogRead(IR_D2);
    sensores->sensorValues[1] = analogRead(IR_D3);
    sensores->sensorValues[2] = analogRead(IR_D4);
    sensores->sensorValues[3] = analogRead(IR_D5);
    sensores->sensorValues[4] = analogRead(IR_D6);
    sensores->sensorValues[5] = analogRead(IR_D7);

    //Cálculo del valor medido
    int weightedSum = 0;
    int totalWeight = 0;
    for (int i = 0; i < 6; i++) {
        weightedSum += sensores->sensorValues[i] * sensores->sensorWeights[i];
        totalWeight += sensores->sensorValues[i];
    }
    sensores->measuredValue = float(weightedSum) / float(totalWeight);

    //Impresión de los valores de los sensores
    Serial_print(0);
    for (int i = 0; i < 6; i++) {
        Serial_print(sensores->sensorValues[i]);
    }
    Serial_print(0);
    Serial_print(sensores->measuredValue);

    return sensores->measuredValue;
}