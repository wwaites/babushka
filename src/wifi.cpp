#include <ESP8266WiFi.h>
#include "project.h"
#include "logging.h"
#include "wifi.h"

char *sysname;

void setup_wifi() {
  byte mac[6];
  char host[16];
  sysname = host;

#if WIFI_APMODE
  WiFi.mode(WIFI_AP);
  WiFi.softAP(WIFI_SSID, WIFI_PSK);
#else
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PSK);
  WiFi.macAddress(mac);

  snprintf(host, sizeof(host), "%s-%02x%02%02x", HOSTNAME, mac[4], mac[5], mac[6]);
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    delay(5000);
    ESP.restart();
  }
#endif


//  pointless because no logging yet
//  IPAddress addr = WiFi.localIP();
//  syslog.logf(LOG_INFO, "booted with ip address %d.%d.%d.%d", addr[0], addr[1], addr[2], addr[3]);
}
