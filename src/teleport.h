#ifndef _TELEPORT_H
#define _TELEPORT_H

extern unsigned long teleported;
void setup_teleport();

/*
 * Network server that listens to packets on UDP port. It's
 * a Type-Value protocol. There is only one type implemented
 * and it is for motor control.
 *
 * Motor placement packet
 *
 * +--------+--------+--------+--------+--------+
 * | 8 bits | 8 bits | 8 bits | 8 bits | 8 bits |
 * +--------+--------+--------+--------+--------+
 * |  0x01  |  CMD1  |  VAL1  |  CMD2  |  VAL2  |
 * +--------+--------+--------+--------+--------+
 *
 * Where:
 *     CMD1 is 1 for forward motor 1 and 0 reverse
 *     CMD2 is 4 for forward motor 2 and 5 reverse
 *
 * And values range from 0 to 127 for speed.
 *
 */
char *teleport();

#endif /* _TELEPORT_H */
