#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include "project.h"
#include "logging.h"
#include "sabertooth.h"

WiFiUDP TelePort;
char pktbuf[8];
unsigned long teleported = 0;

void setup_teleport() {
    if (TelePort.begin(TELE_PORT) == 1) {
        syslog.logf(LOG_INFO, "listening on udp:///%d.", TELE_PORT);
    } else {
        syslog.logf(LOG_ERR, "unable to listen on udp:///%d.", TELE_PORT);
    }
}

// returns the first four or eight bytes of a UDP
// packet received, or NULL.
void teleport() {
    int pktsiz = TelePort.parsePacket();
    if (pktsiz <= 0) return;

    int pktlen = TelePort.read(pktbuf, 8);

    if (!pktlen || pktlen % 4 != 0) {
        syslog.logf(LOG_INFO, "malformed packet of length %d bytes.", pktlen);
        return;
    }

    teleported = millis();

    digitalWrite(LED_BUILTIN, HIGH);
    saberSerial.write(pktbuf, pktlen);
    digitalWrite(LED_BUILTIN, LOW);
}
