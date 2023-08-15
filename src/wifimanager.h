#ifndef WIFI_MANAGER_H
#define WIFI_MANAGER_H

#include <Arduino.h>
#include <WiFi.h>

String get_mac_address();
void wifi_connection(const char* ssid, const char* password);
bool is_internet();
int get_rssi_strength_bars();
void setWiFiSleep(bool enableSleep);
void changeWiFiMode(wifi_mode_t mode);
#endif // WIFI_MANAGER_H
