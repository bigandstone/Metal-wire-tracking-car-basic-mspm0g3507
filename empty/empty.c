/*
left motor---u7---encoder2---A:PB15,B:PB16;
                ---tb6612_B    
right motor---u6---encoder1---A:PB06,B:PB07;
                ---tb6612_A
*/
#include <stdio.h>
#include "COMMON.h"
#include "encoder.h"
#include "bsp_tb6612.h"
#include "ldc1000.h"
#include "servo.h"

#define LEFT_ANGLE  45
#define RIGHT_ANGLE 135
#define LEFT_SPEED  13
#define RIGHT_SPEED 15
#define COIN_PROX   30000
#define PROX_MID    24100

uint32_t cnt_s = 0;
uint16_t angle = 90;

uint32_t cnt_ms  = 0;
uint8_t  cnt_sec = 0;
uint8_t  cnt_min = 0;

int distance = 0;
int dis_m = 0;
int dis_cm = 0;

void TIME_Proc() {
    cnt_sec = cnt_ms / 1000 % 60;
    cnt_min = cnt_ms / 1000 / 60;
}

void Distance_Proc(){
    distance = (Motor_get_distance(0) + Motor_get_distance(1)) * 6.8 * 3.14 / 2080;
    dis_m = distance / 100;
    dis_cm = distance % 100;
}

void Servo_Proc(){
    Servo_set_angle(angle);
    
    if(cnt_s < 35) return;
    else cnt_s = 0;
    
    if(ProximityData > PROX_MID) angle = (angle <= LEFT_ANGLE)? LEFT_ANGLE : angle - 1;
    else angle = (angle >= RIGHT_ANGLE)? RIGHT_ANGLE : angle + 1;
}

void Buzzer_Proc(){
    static uint16_t tick;
    if(ProximityData >= COIN_PROX) {
        tick ++;
        if(tick > 3) DL_GPIO_clearPins(BUZZER_PORT, BUZZER_IO_PIN);
    }else {
        tick  = 0;
        DL_GPIO_setPins(BUZZER_PORT, BUZZER_IO_PIN);
    }
}

void Motor_Proc(){
        TB6612_SetLeftSpeed(1,LEFT_SPEED);
        TB6612_SetRightSpeed(1,RIGHT_SPEED);
}

void SHOW_Proc() {
    
    static char buff[20];
    sprintf(buff, "Time: %02d:%02d",cnt_min,cnt_sec);
    tft180_show_string(0,Line * 0,buff);
    tft180_show_int(0,Line * 1,cnt_ms,10);
    sprintf(buff, "Dist:%02dm%02dcm",dis_m,dis_cm);
    tft180_show_string(0,Line * 2,buff);
//    
//    sprintf(buff, "L_cnt:%08d",Motor_get_distance(0));
//    tft180_show_string(0,60,buff);
//    sprintf(buff, "R_cnt:%08d",Motor_get_distance(1));
//    tft180_show_string(0,80,buff);
////    
//    sprintf(buff, "L_speed:%09d    ",Motor_get_speed(0));
//    tft180_show_string(0,60,buff);
//    sprintf(buff, "R_speed:%09d    ",Motor_get_speed(1));
//    tft180_show_string(0,80,buff);

    sprintf(buff, "Prox:%06d",ProximityData);
    tft180_show_string(0,Line * 3,buff);
    tft180_show_int(0,Line * 5,cnt_s,10);
    sprintf(buff, "Angle:%06d",angle);
    tft180_show_string(0,Line * 6,buff);
}

int main(void)
{
    SYSCFG_DL_init();
    tft180_init();
    Motor_Init();
    LDC1000_Init();
    
    while (1) {
        SHOW_Proc();
        TIME_Proc();
        Distance_Proc();
        LDC1000_ReadData();
        Buzzer_Proc();
        Motor_Proc();
    }
}

//1ms
void SysTick_Handler(void) {
    cnt_s++;
    cnt_ms ++;

    Servo_Proc();
}
//void TIMER_0_INST_IRQHandler(void)
//{
//    

//}