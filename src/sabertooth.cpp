#include <SoftwareSerial.h>
#include "project.h"
#include "sabertooth.h"

SoftwareSerial saberSerial(SABER_RX, SABER_TX); // RX, TX

void setup_sabertooth() {
    saberSerial.begin(9600);
}

void saber_halt() {
    unsigned char halt[] = { 128, 1, 0, 1, 128, 4, 0, 4 };
    saberSerial.write(halt, 8);
}
