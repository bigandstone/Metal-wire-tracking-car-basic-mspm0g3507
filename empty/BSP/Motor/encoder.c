#include "encoder.h"
#include "ti_msp_dl_config.h"

static int encoder_l_cnt;
static int encoder_r_cnt;

static int encoder_l_cnt_prev;
static int encoder_r_cnt_prev;

static int encoder_l_speed;
static int encoder_r_speed;

void Motor_Init(void)
{
	NVIC_EnableIRQ(ENCODER_INT_IRQN);
//    NVIC_EnableIRQ(TIMER_0_INST_INT_IRQN);
}

int Motor_get_distance(int dir)
{
	if( !dir ) return encoder_l_cnt;
	else return encoder_r_cnt;
}

int Motor_get_speed(int dir)
{
	if( !dir ) return encoder_l_speed;
	else return encoder_r_speed;
}

void GROUP1_IRQHandler(void)
{
    static uint8_t sum;
    switch( DL_Interrupt_getPendingGroup(DL_INTERRUPT_GROUP_1))
    {
        case ENCODER_INT_IIDX:
            if(DL_GPIO_getEnabledInterruptStatus(ENCODER_PORT, ENCODER_LA_PIN))
            {
                sum = 1;
                if(DL_GPIO_readPins(ENCODER_PORT,ENCODER_LA_PIN)) sum++;
                if(DL_GPIO_readPins(ENCODER_PORT,ENCODER_LB_PIN)) sum++;
                if(sum==0||sum==2) encoder_l_cnt--;
                else encoder_l_cnt++;
                DL_GPIO_clearInterruptStatus(ENCODER_PORT, ENCODER_LA_PIN);
            }
            if(DL_GPIO_getEnabledInterruptStatus(ENCODER_PORT, ENCODER_LB_PIN))
            {
                sum = 0;
                if(DL_GPIO_readPins(ENCODER_PORT,ENCODER_LA_PIN)) sum++;
                if(DL_GPIO_readPins(ENCODER_PORT,ENCODER_LB_PIN)) sum++;
                if(sum==0||sum==2) encoder_l_cnt--;
                else encoder_l_cnt++;
                DL_GPIO_clearInterruptStatus(ENCODER_PORT, ENCODER_LB_PIN);
            }
            
            if(DL_GPIO_getEnabledInterruptStatus(ENCODER_PORT, ENCODER_RA_PIN))
            {
                sum = 1;
                if(DL_GPIO_readPins(ENCODER_PORT,ENCODER_RA_PIN)) sum++;
                if(DL_GPIO_readPins(ENCODER_PORT,ENCODER_RB_PIN)) sum++;
                if(sum==0||sum==2) encoder_r_cnt++;
                else encoder_r_cnt--;
                DL_GPIO_clearInterruptStatus(ENCODER_PORT, ENCODER_RA_PIN);
            }
            if(DL_GPIO_getEnabledInterruptStatus(ENCODER_PORT, ENCODER_RB_PIN))
            {
                sum = 0;
                if(DL_GPIO_readPins(ENCODER_PORT,ENCODER_RA_PIN)) sum++;
                if(DL_GPIO_readPins(ENCODER_PORT,ENCODER_RB_PIN)) sum++;
                if(sum==0||sum==2) encoder_r_cnt++;
                else encoder_r_cnt--;
                DL_GPIO_clearInterruptStatus(ENCODER_PORT, ENCODER_RB_PIN);
            }
        break;
    }
}


