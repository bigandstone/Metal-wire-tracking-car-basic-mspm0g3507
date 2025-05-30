#ifndef	__ENCODER_H__
#define __ENCODER_H__

#include <stdint.h>

#define ABS(a)      (a>0 ? a:(-a))

#define BeiPing     4
#define PPR         13
#define JianSuBi    20

void Motor_Init(void);
int  Motor_get_distance(int dir);
int  Motor_get_speed(int dir);
void Motor_Stop(void);

#endif
