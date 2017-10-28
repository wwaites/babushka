#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <Syslog.h>
#include <ArduinoOTA.h>

#include "project.h"
#include "wifi.h"
#include "logging.h"
#include "sabertooth.h"
#include "ota.h"
#include "teleport.h"

void setup() {
  setup_wifi();
  setup_logging();
  setup_ota();
  setup_sabertooth();
  setup_teleport();

  syslog.logf(LOG_INFO, "telepresence robot starting...");

  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  ArduinoOTA.handle();
  teleport();
}
