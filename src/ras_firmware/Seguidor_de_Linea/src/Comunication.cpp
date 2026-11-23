#include <Arduino.h>
#include <WiFi.h>
#include "Comunication.h"

const char* ssid = "Tu_WiFi";
const char* password = "Tu_Contraseña";

bool Wifi_init() {
    Serial.begin(115200);
    WiFi.begin(ssid, password);

    int trys = 0;

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.println("Conectando...");
        trys++;
        if(trys > 20) {
            Serial.println("No se pudo conectar a la red WiFi");
            return false;
        }
    }
    Serial.println("Conectado");
    Serial.println(WiFi.localIP());
  
    return true;
}

void Serial_print(int message) {
    Serial.println(message);
}