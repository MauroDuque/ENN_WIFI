#ifndef WIFIMANAGER_H
#define WIFIMANAGER_H

void rssi_loop();
int get_rssi_strength_bars();
int get_rssi_strength();

void wifi_connection(const char* ssid, const char* password);
bool is_internet();
String get_mac();
#endif