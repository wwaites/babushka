#ifndef _SABERTOOTH_H
#define _SABERTOOTH_H

#include <SoftwareSerial.h>

extern SoftwareSerial saberSerial;

void setup_sabertooth();
void saber_set(unsigned char *);
void saber_halt();

#endif /* _SABERTOOH_ */
