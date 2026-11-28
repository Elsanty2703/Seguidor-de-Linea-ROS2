#include <Arduino.h>
#include <stdio.h>
#include <WiFi.h>
#include "Comunication.h"

const char* ssid = "iPhone de Elsanty";
const char* password = "Santy2703Gamboa";

bool Wifi_init() {

    Serial.begin(115200);
    WiFi.begin(ssid, password);

    int trys = 0;

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        trys++;
        if(trys > 20) {
            Serial.println("Failed to connect to WiFi");
            return false;
        }
    }
    Serial.println("Connected to WiFi. IP address: " + WiFi.localIP().toString());
    return true;
}

void Serial_print(int message) {
    Serial.println(message);
}