#ifndef __servo_h
#define __servo_h

#include "stdint.h"

#define ANGLE_MAX 100
#define ANGLE_MIN 80

void Servo_init(void);
void Servo_set_angle(uint8_t angle);

#endif