#include <SoftwareSerial.h>
#include "project.h"
#include "sabertooth.h"

SoftwareSerial saberSerial(SABER_RX, SABER_TX); // RX, TX

void setup_sabertooth() {
    saberSerial.begin(9600);
}

void saber_set(unsigned char *pktbuf) {
    unsigned char cmdbuf[8];
    cmdbuf[0] = 128;
    cmdbuf[1] = pktbuf[0];
    cmdbuf[2] = pktbuf[1];
    cmdbuf[3] = (128 + pktbuf[0] + pktbuf[1]) & 0x7f;
    cmdbuf[4] = 128;
    cmdbuf[5] = pktbuf[2];
    cmdbuf[6] = pktbuf[3];
    cmdbuf[7] = (128 + pktbuf[2] + pktbuf[3]) & 0x7f;
    saberSerial.write(cmdbuf, 8);
}

void saber_halt() {
    unsigned char halt[] = { 1, 0, 4, 0 };
    saber_set(halt);
}
