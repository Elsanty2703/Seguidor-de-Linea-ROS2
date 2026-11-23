#include "Control.h"

void Control_init(Control* control, unsigned long Ts, int velBase) {

    pinMode(STBY, OUTPUT);
    digitalWrite(STBY, LOW);
    pinMode(START, INPUT);
    pinMode(STOP, INPUT);

    control->start = false;
    control->stby = false;
    control->time = 0;
    control->ts = Ts;
    control->velbase = velBase;
}

void Control_setStart(Control* control, bool value) {
    control->start = value;
}

void Control_setStby(Control* control, bool value) {
    control->stby = value;
    digitalWrite(STBY, value ? HIGH : LOW);
}

void Control_setTime(Control* control) {
    control->time = millis();
}

void Control_setVelBase(Control* control, int velBase) {
    control->velbase = velBase;
}

bool Control_getStart(Control* control) {
    return control->start;
}

bool Control_getStby(Control* control) {
    return control->stby;
}

bool Control_getTime(Control* control) {
    if(millis() - control->time >= control->ts) {
        return true;
    } else {
        return false;
    }
}

int Control_getVelBase(Control* control) {
    return control->velbase;
}
