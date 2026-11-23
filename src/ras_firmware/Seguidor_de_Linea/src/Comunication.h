#ifndef COMUNICATION_H  // 1. Guarda de inclusión: evita que el archivo se compile dos veces
#define COMUNICATION_H

#include <Arduino.h>

bool Wifi_init();

void Serial_print(int message);

#endif // COMUNICATION_H (Cierre de la guarda de inclusión)
