#ifndef CONTROL_H  // 1. Guarda de inclusión: evita que el archivo se compile dos veces
#define CONTROL_H

#include <Arduino.h>

#define START 19
#define STOP 18
#define STBY 13

struct Control {
    bool start;
    bool stby;
    unsigned long time;
    unsigned long ts;
    int velbase;
};

void Control_init(Control* control, unsigned long Ts, int velBase);

void Control_setStart(Control* control, bool value);
void Control_setStby(Control* control, bool value);
void Control_setTime(Control* control);
void Control_setVelBase(Control* control, int velBase);

bool Control_getStart(Control* control);
bool Control_getStby(Control* control);
bool Control_getTime(Control* control);
int Control_getVelBase(Control* control);

#endif // CONTROL_H (Cierre de la guarda de inclusión)
