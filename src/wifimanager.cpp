#include "WiFi.h"

const char* ssid_default = "Enerinno";
const char* soft_ap_password = NULL;

struct NetworkInfo {
  String ssid;
  int strength;
};

String get_mac_address() {
    return WiFi.macAddress();
}

// ======================WIFI Scann =================================
NetworkInfo* get_networks() {
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();

  Serial.println("Scanning for WiFi networks...");
  int networks = WiFi.scanNetworks();

  if (networks == 0) {
    Serial.println("No WiFi networks found.");
    return nullptr; // No networks found, return nullptr
  } else {
    NetworkInfo* networkList = new NetworkInfo[networks];

    for (int i = 0; i < networks; ++i) {
      networkList[i].ssid = WiFi.SSID(i);
      networkList[i].strength = WiFi.RSSI(i);
      delay(10);
    }

    return networkList;
  }
}


// ======================WIFI=================================

// Function to change WiFi mode

void changeWiFiMode(wifi_mode_t mode) {
    WiFi.mode(mode);
}
// Function to control WiFi sleep mode
void setWiFiSleep(bool enableSleep) {
    WiFi.setSleep(enableSleep);
}

void wifi_connection(const char* ssid, const char* password) {
    changeWiFiMode(WIFI_AP_STA);

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
