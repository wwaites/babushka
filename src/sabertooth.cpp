#include <SoftwareSerial.h>
#include "project.h"
#include "sabertooth.h"

SoftwareSerial saberSerial(SABER_RX, SABER_TX); // RX, TX

void setup_sabertooth() {
     saberSerial.begin(9600);
}
