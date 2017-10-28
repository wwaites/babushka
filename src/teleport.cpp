#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include "project.h"
#include "logging.h"
#include "sabertooth.h"

WiFiUDP TelePort;
unsigned char pktbuf[5];
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

    int pktlen = TelePort.read(pktbuf, 5);

    if (pktlen < 1) {
        syslog.logf(LOG_WARNING, "malformed packet of length %d bytes.", pktlen);
        return;
    }

    digitalWrite(LED_BUILTIN, HIGH);
    switch (pktbuf[0]) {
        case 1: // Control motor
            if (pktlen != 5) {
                syslog.logf(LOG_WARNING, "malformed motor placement packet of %d bytes.", pktlen);
                break;
            }
            saber_set(pktbuf+1);
            teleported = millis();
            break;
        default:
            syslog.logf(LOG_WARNING, "unknown packet format %d.", pktbuf[0]);
            break;
    }
    digitalWrite(LED_BUILTIN, LOW);
}
