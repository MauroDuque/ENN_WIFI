#include "WiFi.h"

const char* ssid_default = "Enerinno";
const char* soft_ap_password = NULL;

String get_mac_address() {
    return WiFi.macAddress();
}

// Function to change WiFi mode
// TODO
void changeWiFiMode(int modeSelection) {
    wifi_mode_t mode;

    switch (modeSelection) {
        case 1:
            mode = WIFI_STA;
            break;
        case 2:
            mode = WIFI_AP;
            break;
        case 3:
            mode = WIFI_AP_STA;
            break;
        // Add more cases for different WiFi modes if needed
        default:
            mode = WIFI_STA; // Default mode
    }

    WiFi.mode(mode);
}
// Function to control WiFi sleep mode
void setWiFiSleep(bool enableSleep) {
    WiFi.setSleep(enableSleep);
}

void wifi_connection(const char* ssid, const char* password) {
    changeWiFiMode.mode(WIFI_AP_STA);

    String soft_ap_ssid = String(ssid_default) + WiFi.macAddress();
    WiFi.softAP(soft_ap_ssid.c_str(), soft_ap_password);
    Serial.print("Access Point IP address: ");
    Serial.println(WiFi.softAPIP());

    WiFi.begin(ssid, password);
}

bool is_internet() {
    if (WiFi.status() != WL_CONNECTED) {
        return false;
    }
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());

    return true;
}

int get_rssi_strength_bars() {
    int rssi = WiFi.RSSI();
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
