#include "servo.h"
#include "ti_msp_dl_config.h"

void Servo_init(void){
    DL_TimerG_setCaptureCompareValue(SERVO_INST,1500,GPIO_SERVO_C0_IDX);
}
void Servo_set_angle(uint8_t angle){
    uint16_t pulse;
//    if(angle > ANGLE_MAX) angle = ANGLE_MAX;
//    if(angle < ANGLE_MAX) angle = ANGLE_MIN;
    pulse = 500 + (2500 - 500) * angle / 180;
    DL_TimerG_setCaptureCompareValue(SERVO_INST,pulse,GPIO_SERVO_C0_IDX);
}