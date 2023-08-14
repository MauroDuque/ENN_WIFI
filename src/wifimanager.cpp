#include "WiFi.h"

const char *ssid_default = "Enerinno";

String macaddress = WiFi.macAddress();
const char* stringmac = macaddress.c_str();
const char *ssid_mac = stringmac;
char* soft_ap_password = NULL;

char soft_ap_ssid[30]
int bars_rssi = 0;
int rssi = 0;

int get_rssi_strength() {
    return rssi;
}

int get_rssi_strength_bars() {
    return bars_rssi;
}

int rssiToBars(int rssi) {
    if (rssi >= -50) {
        return 4;
    } else if (rssi >= -60) {
        return 3;
    } else if (rssi >= -70) {
        return 2;
    } else if (rssi >= -80) {
        return 1;
    } else {
        return 0;
    }
}

void rssi_loop() {
    rssi = WiFi.RSSI();  // Get RSSI value in dBm
    bars_rssi = rssiToBars(rssi);

    Serial.print("RSSI: ");
    Serial.print(rssi);
    Serial.print(" dBm, Bars: ");
    Serial.println(bars_rssi);
}

String get_mac() {
    return macaddress;
}

void wifi_connection(const char* ssid, const char* password) {
    char soft_ap_ssid[64]; // Adjust the array size as needed
    strcpy(soft_ap_ssid, ssid_default);
    strcat(soft_ap_ssid, ssid_mac);

    Serial.println("Setting AP (Access Point & Station)");
    WiFi.mode(WIFI_AP_STA);

    WiFi.softAP(soft_ap_ssid, soft_ap_password);
    Serial.print("Access Point IP address: ");
    Serial.println(WiFi.softAPIP()); // Print the IP address of the Access Point

    WiFi.begin(ssid, password);

    Serial.println("NetWork: ");
    Serial.println(soft_ap_ssid);
}

bool is_internet() {
    if (WiFi.status() != WL_CONNECTED) {
        return false;
    }
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());

    return true;
}