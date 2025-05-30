#include "bsp_tb6612.h"

void TB6612_Motor_Stop(void)
{
    AIN1_OUT(1);
    AIN2_OUT(1);
    BIN1_OUT(1);
    BIN2_OUT(1);        
}

void TB6612_SetRightSpeed(uint8_t dir, uint32_t speed)
{
    if(dir){
        AIN1_OUT(0);
        AIN2_OUT(1);
    }
    else{
        AIN1_OUT(1);
        AIN2_OUT(0);
    }
    DL_TimerG_setCaptureCompareValue(TB6612_PWM_INST, speed, GPIO_TB6612_PWM_C1_IDX);
}

void TB6612_SetLeftSpeed(uint8_t dir, uint32_t speed)
{
    if( dir)
    {
        BIN1_OUT(0);
        BIN2_OUT(1);
    }
    else{
        BIN1_OUT(1);
        BIN2_OUT(0);
    }
    DL_TimerG_setCaptureCompareValue(TB6612_PWM_INST, speed, GPIO_TB6612_PWM_C0_IDX);
}
