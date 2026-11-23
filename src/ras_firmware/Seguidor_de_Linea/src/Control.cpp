#include "Control.h"

void Control_init(Control* control) {

    pinMode(STBY, OUTPUT);
    digitalWrite(STBY, LOW);
    pinMode(START, INPUT);
    pinMode(STOP, INPUT);

    control->start = false;
    control->stby = false;
}

void Control_setStart(Control* control, bool value) {
    control->start = value;
}

void Control_setStby(Control* control, bool value) {
    control->stby = value;
    digitalWrite(STBY, value ? HIGH : LOW);
}

bool Control_getStart(Control* control) {
    return control->start;
}

bool Control_getStby(Control* control) {
    return control->stby;
}
