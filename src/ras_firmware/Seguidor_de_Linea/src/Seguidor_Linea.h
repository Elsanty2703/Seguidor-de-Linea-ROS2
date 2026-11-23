#ifndef SEGUIDOR_LINEA_H  // 1. Guarda de inclusión: evita que el archivo se compile dos veces
#define SEGUIDOR_LINEA_H

#include <Arduino.h>
#include "Control.h"
#include "Motor.h"
#include "Sensores.h"
#include "PID.h"

void SeguidorLinea_init(Control* control, Motor* motores, Sensores* sensores, PID* pid);

#endif // SEGUIDOR_LINEA_H (Cierre de la guarda de inclusión)
