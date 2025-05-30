#ifndef _BSP_TB6612_H
#define _BSP_TB6612_H

#include <stdint.h>
#include "ti_msp_dl_config.h"

#define AIN1_OUT(X)  ( (X) ? (DL_GPIO_setPins(TB6612_A_PORT,TB6612_A_AIN1_PIN)) : (DL_GPIO_clearPins(TB6612_A_PORT,TB6612_A_AIN1_PIN)) )
#define AIN2_OUT(X)  ( (X) ? (DL_GPIO_setPins(TB6612_A_PORT,TB6612_A_AIN2_PIN)) : (DL_GPIO_clearPins(TB6612_A_PORT,TB6612_A_AIN2_PIN)) )

#define BIN1_OUT(X)  ( (X) ? (DL_GPIO_setPins(TB6612_B_PORT,TB6612_B_BIN1_PIN)) : (DL_GPIO_clearPins(TB6612_B_PORT,TB6612_B_BIN1_PIN)) )
#define BIN2_OUT(X)  ( (X) ? (DL_GPIO_setPins(TB6612_B_PORT,TB6612_B_BIN2_PIN)) : (DL_GPIO_clearPins(TB6612_B_PORT,TB6612_B_BIN2_PIN)) )

void TB6612_Motor_Stop(void);
void TB6612_SetLeftSpeed(uint8_t dir, uint32_t speed);
void TB6612_SetRightSpeed(uint8_t dir, uint32_t speed);

#endif  /* _BSP_TB6612_H */
