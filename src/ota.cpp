#include <ArduinoOTA.h>
#include "project.h"
#include "logging.h"
#include "wifi.h"
#include "ota.h"

void setup_ota() {
  ArduinoOTA.setPort(OTA_PORT);
  ArduinoOTA.setHostname(HOSTNAME); //sysname);

  /*
#ifdef OTA_PASS
  ArduinoOTA.setPassword(OTA_PASS);
#endif
#ifdef OTA_HASH
  ArduinoOTA.setPasswordHash(OTA_HASH);
#endif
  */

  ArduinoOTA.onStart([]() {
      String type;
      if (ArduinoOTA.getCommand() == U_FLASH)
        type = "sketch";
      else // U_SPIFFS
        type = "filesystem";
      // NOTE: if updating SPIFFS this would be the place to unmount SPIFFS using SPIFFS.end()
      syslog.log(LOG_INFO, "OTA start updating %s" + type);
    });
  ArduinoOTA.onEnd([]() {
      syslog.log(LOG_INFO, "OTA end");
    });
  //  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
  //    syslog.logf(LOG_INFO, "OTA progress: %u%%", (progress / (total / 100)));
  //  });
  ArduinoOTA.onError([](ota_error_t error) {
      String strerr = "OTA error: ";

      if (error == OTA_AUTH_ERROR) strerr += "Auth Failed";
      else if (error == OTA_BEGIN_ERROR) strerr += "Begin Failed";
      else if (error == OTA_CONNECT_ERROR) strerr += "Connect Failed";
      else if (error == OTA_RECEIVE_ERROR) strerr += "Receive Failed";
      else if (error == OTA_END_ERROR) strerr += "End Failed";

      syslog.log(LOG_ERR, strerr); //, error);
    });

  ArduinoOTA.begin();
}
