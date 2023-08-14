#ifndef WIFIMANAGER_H
#define WIFIMANAGER_H

void wifi_connection(const char* ssid, const char* password);
bool is_internet();
String get_mac();
#endif