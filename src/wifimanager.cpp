#include "WiFi.h"
#include "settings.h"

const char *ssid_default = "Enerinno";

String macaddress = WiFi.macAddress();
const char* stringmac = macaddress.c_str();
const char *ssid_mac = stringmac;
char* soft_ap_password = NULL;

char soft_ap_ssid[30];

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

void wifi_setup() {
    wifi_connection();
}