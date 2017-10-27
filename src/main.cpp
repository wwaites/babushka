#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <Syslog.h>
#include <ArduinoOTA.h>

#include "project.h"
#include "wifi.h"
#include "logging.h"
#include "sabertooth.h"
#include "ota.h"

void setup() {
  setup_wifi();
  setup_logging();
  setup_ota();
  setup_sabertooth();

  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  ArduinoOTA.handle();
  digitalWrite(LED_BUILTIN, HIGH);
  syslog.logf(LOG_INFO, "hello hello");
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}
