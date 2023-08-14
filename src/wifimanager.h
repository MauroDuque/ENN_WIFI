#ifndef WIFIMANAGER_H
#define WIFIMANAGER_H

#include <Arduino.h>
#include "WiFi.h"

int get_rssi_strength_bars();
void wifi_connection(const char* ssid, const char* password);
bool is_internet();
String get_mac();
#endif