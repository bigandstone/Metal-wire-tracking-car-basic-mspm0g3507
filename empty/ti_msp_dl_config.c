/*
 * Copyright (c) 2023, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 *  ============ ti_msp_dl_config.c =============
 *  Configured MSPM0 DriverLib module definitions
 *
 *  DO NOT EDIT - This file is generated for the MSPM0G350X
 *  by the SysConfig tool.
 */

#include "ti_msp_dl_config.h"

DL_TimerA_backupConfig gTB6612_PWMBackup;
DL_TimerG_backupConfig gLDC_CLKBackup;
DL_SPI_backupConfig gTFT_SPIBackup;
DL_SPI_backupConfig gSPI_LDCBackup;

/*
 *  ======== SYSCFG_DL_init ========
 *  Perform any initialization needed before using any board APIs
 */
SYSCONFIG_WEAK void SYSCFG_DL_init(void)
{
    SYSCFG_DL_initPower();
    SYSCFG_DL_GPIO_init();
    /* Module-Specific Initializations*/
    SYSCFG_DL_SYSCTL_init();
    SYSCFG_DL_TB6612_PWM_init();
    SYSCFG_DL_LDC_CLK_init();
    SYSCFG_DL_SERVO_init();
    SYSCFG_DL_TIMER_0_init();
    SYSCFG_DL_UART_0_init();
    SYSCFG_DL_TFT_SPI_init();
    SYSCFG_DL_SPI_LDC_init();
    SYSCFG_DL_SYSTICK_init();
    /* Ensure backup structures have no valid state */
	gTB6612_PWMBackup.backupRdy 	= false;
	gLDC_CLKBackup.backupRdy 	= false;


	gTFT_SPIBackup.backupRdy 	= false;
	gSPI_LDCBackup.backupRdy 	= false;

}
/*
 * User should take care to save and restore register configuration in application.
 * See Retention Configuration section for more details.
 */
SYSCONFIG_WEAK bool SYSCFG_DL_saveConfiguration(void)
{
    bool retStatus = true;

	retStatus &= DL_TimerA_saveConfiguration(TB6612_PWM_INST, &gTB6612_PWMBackup);
	retStatus &= DL_TimerG_saveConfiguration(LDC_CLK_INST, &gLDC_CLKBackup);
	retStatus &= DL_SPI_saveConfiguration(TFT_SPI_INST, &gTFT_SPIBackup);
	retStatus &= DL_SPI_saveConfiguration(SPI_LDC_INST, &gSPI_LDCBackup);

    return retStatus;
}


SYSCONFIG_WEAK bool SYSCFG_DL_restoreConfiguration(void)
{
    bool retStatus = true;

	retStatus &= DL_TimerA_restoreConfiguration(TB6612_PWM_INST, &gTB6612_PWMBackup, false);
	retStatus &= DL_TimerG_restoreConfiguration(LDC_CLK_INST, &gLDC_CLKBackup, false);
	retStatus &= DL_SPI_restoreConfiguration(TFT_SPI_INST, &gTFT_SPIBackup);
	retStatus &= DL_SPI_restoreConfiguration(SPI_LDC_INST, &gSPI_LDCBackup);

    return retStatus;
}

SYSCONFIG_WEAK void SYSCFG_DL_initPower(void)
{
    DL_GPIO_reset(GPIOA);
    DL_GPIO_reset(GPIOB);
    DL_TimerA_reset(TB6612_PWM_INST);
    DL_TimerG_reset(LDC_CLK_INST);
    DL_TimerG_reset(SERVO_INST);
    DL_TimerG_reset(TIMER_0_INST);
    DL_UART_Main_reset(UART_0_INST);
    DL_SPI_reset(TFT_SPI_INST);
    DL_SPI_reset(SPI_LDC_INST);


    DL_GPIO_enablePower(GPIOA);
    DL_GPIO_enablePower(GPIOB);
    DL_TimerA_enablePower(TB6612_PWM_INST);
    DL_TimerG_enablePower(LDC_CLK_INST);
    DL_TimerG_enablePower(SERVO_INST);
    DL_TimerG_enablePower(TIMER_0_INST);
    DL_UART_Main_enablePower(UART_0_INST);
    DL_SPI_enablePower(TFT_SPI_INST);
    DL_SPI_enablePower(SPI_LDC_INST);

    delay_cycles(POWER_STARTUP_DELAY);
}

SYSCONFIG_WEAK void SYSCFG_DL_GPIO_init(void)
{

    DL_GPIO_initPeripheralOutputFunction(GPIO_TB6612_PWM_C0_IOMUX,GPIO_TB6612_PWM_C0_IOMUX_FUNC);
    DL_GPIO_enableOutput(GPIO_TB6612_PWM_C0_PORT, GPIO_TB6612_PWM_C0_PIN);
    DL_GPIO_initPeripheralOutputFunction(GPIO_TB6612_PWM_C1_IOMUX,GPIO_TB6612_PWM_C1_IOMUX_FUNC);
    DL_GPIO_enableOutput(GPIO_TB6612_PWM_C1_PORT, GPIO_TB6612_PWM_C1_PIN);
    DL_GPIO_initPeripheralOutputFunction(GPIO_LDC_CLK_C0_IOMUX,GPIO_LDC_CLK_C0_IOMUX_FUNC);
    DL_GPIO_enableOutput(GPIO_LDC_CLK_C0_PORT, GPIO_LDC_CLK_C0_PIN);
    DL_GPIO_initPeripheralOutputFunction(GPIO_SERVO_C0_IOMUX,GPIO_SERVO_C0_IOMUX_FUNC);
    DL_GPIO_enableOutput(GPIO_SERVO_C0_PORT, GPIO_SERVO_C0_PIN);

    DL_GPIO_initPeripheralOutputFunction(
        GPIO_UART_0_IOMUX_TX, GPIO_UART_0_IOMUX_TX_FUNC);
    DL_GPIO_initPeripheralInputFunction(
        GPIO_UART_0_IOMUX_RX, GPIO_UART_0_IOMUX_RX_FUNC);

    DL_GPIO_initPeripheralOutputFunction(
        GPIO_TFT_SPI_IOMUX_SCLK, GPIO_TFT_SPI_IOMUX_SCLK_FUNC);
    DL_GPIO_initPeripheralOutputFunction(
        GPIO_TFT_SPI_IOMUX_PICO, GPIO_TFT_SPI_IOMUX_PICO_FUNC);
    DL_GPIO_initPeripheralInputFunction(
        GPIO_TFT_SPI_IOMUX_POCI, GPIO_TFT_SPI_IOMUX_POCI_FUNC);
    DL_GPIO_initPeripheralOutputFunction(
        GPIO_SPI_LDC_IOMUX_SCLK, GPIO_SPI_LDC_IOMUX_SCLK_FUNC);
    DL_GPIO_initPeripheralOutputFunction(
        GPIO_SPI_LDC_IOMUX_PICO, GPIO_SPI_LDC_IOMUX_PICO_FUNC);
    DL_GPIO_initPeripheralInputFunction(
        GPIO_SPI_LDC_IOMUX_POCI, GPIO_SPI_LDC_IOMUX_POCI_FUNC);

    DL_GPIO_initDigitalOutput(BUZZER_IO_IOMUX);

    DL_GPIO_initDigitalOutput(TFT_RES_IOMUX);

    DL_GPIO_initDigitalOutput(TFT_DC_IOMUX);

    DL_GPIO_initDigitalOutput(TFT_CS_IOMUX);

    DL_GPIO_initDigitalOutput(TFT_BLK_IOMUX);

    DL_GPIO_initDigitalInputFeatures(ENCODER_LA_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_NONE,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalInputFeatures(ENCODER_LB_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_NONE,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalInputFeatures(ENCODER_RA_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_NONE,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalInputFeatures(ENCODER_RB_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_NONE,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalOutput(TB6612_A_AIN1_IOMUX);

    DL_GPIO_initDigitalOutput(TB6612_A_AIN2_IOMUX);

    DL_GPIO_initDigitalOutput(TB6612_B_BIN1_IOMUX);

    DL_GPIO_initDigitalOutput(TB6612_B_BIN2_IOMUX);

    DL_GPIO_initDigitalOutput(LDC_CSB_IOMUX);

    DL_GPIO_initDigitalInputFeatures(LDC_INTB_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_UP,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_setPins(GPIOA, TB6612_A_AIN1_PIN |
		TB6612_A_AIN2_PIN |
		LDC_CSB_PIN);
    DL_GPIO_enableOutput(GPIOA, TB6612_A_AIN1_PIN |
		TB6612_A_AIN2_PIN |
		LDC_CSB_PIN);
    DL_GPIO_clearPins(GPIOB, TFT_RES_PIN |
		TFT_DC_PIN |
		TB6612_B_BIN2_PIN);
    DL_GPIO_setPins(GPIOB, BUZZER_IO_PIN |
		TFT_CS_PIN |
		TFT_BLK_PIN |
		TB6612_B_BIN1_PIN);
    DL_GPIO_enableOutput(GPIOB, BUZZER_IO_PIN |
		TFT_RES_PIN |
		TFT_DC_PIN |
		TFT_CS_PIN |
		TFT_BLK_PIN |
		TB6612_B_BIN1_PIN |
		TB6612_B_BIN2_PIN);
    DL_GPIO_setLowerPinsPolarity(GPIOB, DL_GPIO_PIN_15_EDGE_RISE_FALL |
		DL_GPIO_PIN_6_EDGE_RISE_FALL |
		DL_GPIO_PIN_7_EDGE_RISE_FALL);
    DL_GPIO_setUpperPinsPolarity(GPIOB, DL_GPIO_PIN_16_EDGE_RISE_FALL);
    DL_GPIO_clearInterruptStatus(GPIOB, ENCODER_LA_PIN |
		ENCODER_LB_PIN |
		ENCODER_RA_PIN |
		ENCODER_RB_PIN);
    DL_GPIO_enableInterrupt(GPIOB, ENCODER_LA_PIN |
		ENCODER_LB_PIN |
		ENCODER_RA_PIN |
		ENCODER_RB_PIN);

}



SYSCONFIG_WEAK void SYSCFG_DL_SYSCTL_init(void)
{

	//Low Power Mode is configured to be SLEEP0
    DL_SYSCTL_setBORThreshold(DL_SYSCTL_BOR_THRESHOLD_LEVEL_0);

    
	DL_SYSCTL_setSYSOSCFreq(DL_SYSCTL_SYSOSC_FREQ_BASE);
	/* Set default configuration */
	DL_SYSCTL_disableHFXT();
	DL_SYSCTL_disableSYSPLL();
    /* INT_GROUP1 Priority */
    NVIC_SetPriority(GPIOB_INT_IRQn, 0);

}


/*
 * Timer clock configuration to be sourced by  / 8 (4000000 Hz)
 * timerClkFreq = (timerClkSrc / (timerClkDivRatio * (timerClkPrescale + 1)))
 *   1000000 Hz = 4000000 Hz / (8 * (3 + 1))
 */
static const DL_TimerA_ClockConfig gTB6612_PWMClockConfig = {
    .clockSel = DL_TIMER_CLOCK_BUSCLK,
    .divideRatio = DL_TIMER_CLOCK_DIVIDE_8,
    .prescale = 3U
};

static const DL_TimerA_PWMConfig gTB6612_PWMConfig = {
    .pwmMode = DL_TIMER_PWM_MODE_EDGE_ALIGN_UP,
    .period = 100,
    .isTimerWithFourCC = false,
    .startTimer = DL_TIMER_START,
};

SYSCONFIG_WEAK void SYSCFG_DL_TB6612_PWM_init(void) {

    DL_TimerA_setClockConfig(
        TB6612_PWM_INST, (DL_TimerA_ClockConfig *) &gTB6612_PWMClockConfig);

    DL_TimerA_initPWMMode(
        TB6612_PWM_INST, (DL_TimerA_PWMConfig *) &gTB6612_PWMConfig);

    DL_TimerA_setCaptureCompareOutCtl(TB6612_PWM_INST, DL_TIMER_CC_OCTL_INIT_VAL_LOW,
		DL_TIMER_CC_OCTL_INV_OUT_DISABLED, DL_TIMER_CC_OCTL_SRC_FUNCVAL,
		DL_TIMERA_CAPTURE_COMPARE_0_INDEX);

    DL_TimerA_setCaptCompUpdateMethod(TB6612_PWM_INST, DL_TIMER_CC_UPDATE_METHOD_IMMEDIATE, DL_TIMERA_CAPTURE_COMPARE_0_INDEX);
    DL_TimerA_setCaptureCompareValue(TB6612_PWM_INST, 0, DL_TIMER_CC_0_INDEX);

    DL_TimerA_setCaptureCompareOutCtl(TB6612_PWM_INST, DL_TIMER_CC_OCTL_INIT_VAL_LOW,
		DL_TIMER_CC_OCTL_INV_OUT_DISABLED, DL_TIMER_CC_OCTL_SRC_FUNCVAL,
		DL_TIMERA_CAPTURE_COMPARE_1_INDEX);

    DL_TimerA_setCaptCompUpdateMethod(TB6612_PWM_INST, DL_TIMER_CC_UPDATE_METHOD_IMMEDIATE, DL_TIMERA_CAPTURE_COMPARE_1_INDEX);
    DL_TimerA_setCaptureCompareValue(TB6612_PWM_INST, 0, DL_TIMER_CC_1_INDEX);

    DL_TimerA_enableClock(TB6612_PWM_INST);


    
    DL_TimerA_setCCPDirection(TB6612_PWM_INST , DL_TIMER_CC0_OUTPUT | DL_TIMER_CC1_OUTPUT );


}
/*
 * Timer clock configuration to be sourced by  / 1 (32000000 Hz)
 * timerClkFreq = (timerClkSrc / (timerClkDivRatio * (timerClkPrescale + 1)))
 *   32000000 Hz = 32000000 Hz / (1 * (0 + 1))
 */
static const DL_TimerG_ClockConfig gLDC_CLKClockConfig = {
    .clockSel = DL_TIMER_CLOCK_BUSCLK,
    .divideRatio = DL_TIMER_CLOCK_DIVIDE_1,
    .prescale = 0U
};

static const DL_TimerG_PWMConfig gLDC_CLKConfig = {
    .pwmMode = DL_TIMER_PWM_MODE_CENTER_ALIGN,
    .period = 4,
    .isTimerWithFourCC = false,
    .startTimer = DL_TIMER_START,
};

SYSCONFIG_WEAK void SYSCFG_DL_LDC_CLK_init(void) {

    DL_TimerG_setClockConfig(
        LDC_CLK_INST, (DL_TimerG_ClockConfig *) &gLDC_CLKClockConfig);

    DL_TimerG_initPWMMode(
        LDC_CLK_INST, (DL_TimerG_PWMConfig *) &gLDC_CLKConfig);

    DL_TimerG_setCaptureCompareOutCtl(LDC_CLK_INST, DL_TIMER_CC_OCTL_INIT_VAL_LOW,
		DL_TIMER_CC_OCTL_INV_OUT_DISABLED, DL_TIMER_CC_OCTL_SRC_FUNCVAL,
		DL_TIMERG_CAPTURE_COMPARE_0_INDEX);

    DL_TimerG_setCaptCompUpdateMethod(LDC_CLK_INST, DL_TIMER_CC_UPDATE_METHOD_IMMEDIATE, DL_TIMERG_CAPTURE_COMPARE_0_INDEX);
    DL_TimerG_setCaptureCompareValue(LDC_CLK_INST, 1, DL_TIMER_CC_0_INDEX);

    DL_TimerG_enableClock(LDC_CLK_INST);


    
    DL_TimerG_setCCPDirection(LDC_CLK_INST , DL_TIMER_CC0_OUTPUT );


}
/*
 * Timer clock configuration to be sourced by  / 8 (4000000 Hz)
 * timerClkFreq = (timerClkSrc / (timerClkDivRatio * (timerClkPrescale + 1)))
 *   1000000 Hz = 4000000 Hz / (8 * (3 + 1))
 */
static const DL_TimerG_ClockConfig gSERVOClockConfig = {
    .clockSel = DL_TIMER_CLOCK_BUSCLK,
    .divideRatio = DL_TIMER_CLOCK_DIVIDE_8,
    .prescale = 3U
};

static const DL_TimerG_PWMConfig gSERVOConfig = {
    .pwmMode = DL_TIMER_PWM_MODE_EDGE_ALIGN_UP,
    .period = 20000,
    .isTimerWithFourCC = false,
    .startTimer = DL_TIMER_START,
};

SYSCONFIG_WEAK void SYSCFG_DL_SERVO_init(void) {

    DL_TimerG_setClockConfig(
        SERVO_INST, (DL_TimerG_ClockConfig *) &gSERVOClockConfig);

    DL_TimerG_initPWMMode(
        SERVO_INST, (DL_TimerG_PWMConfig *) &gSERVOConfig);

    DL_TimerG_setCaptureCompareOutCtl(SERVO_INST, DL_TIMER_CC_OCTL_INIT_VAL_LOW,
		DL_TIMER_CC_OCTL_INV_OUT_DISABLED, DL_TIMER_CC_OCTL_SRC_FUNCVAL,
		DL_TIMERG_CAPTURE_COMPARE_0_INDEX);

    DL_TimerG_setCaptCompUpdateMethod(SERVO_INST, DL_TIMER_CC_UPDATE_METHOD_IMMEDIATE, DL_TIMERG_CAPTURE_COMPARE_0_INDEX);
    DL_TimerG_setCaptureCompareValue(SERVO_INST, 1500, DL_TIMER_CC_0_INDEX);

    DL_TimerG_enableClock(SERVO_INST);


    
    DL_TimerG_setCCPDirection(SERVO_INST , DL_TIMER_CC0_OUTPUT );


}



/*
 * Timer clock configuration to be sourced by BUSCLK /  (4000000 Hz)
 * timerClkFreq = (timerClkSrc / (timerClkDivRatio * (timerClkPrescale + 1)))
 *   100000 Hz = 4000000 Hz / (8 * (39 + 1))
 */
static const DL_TimerG_ClockConfig gTIMER_0ClockConfig = {
    .clockSel    = DL_TIMER_CLOCK_BUSCLK,
    .divideRatio = DL_TIMER_CLOCK_DIVIDE_8,
    .prescale    = 39U,
};

/*
 * Timer load value (where the counter starts from) is calculated as (timerPeriod * timerClockFreq) - 1
 * TIMER_0_INST_LOAD_VALUE = (10ms * 100000 Hz) - 1
 */
static const DL_TimerG_TimerConfig gTIMER_0TimerConfig = {
    .period     = TIMER_0_INST_LOAD_VALUE,
    .timerMode  = DL_TIMER_TIMER_MODE_PERIODIC,
    .startTimer = DL_TIMER_START,
};

SYSCONFIG_WEAK void SYSCFG_DL_TIMER_0_init(void) {

    DL_TimerG_setClockConfig(TIMER_0_INST,
        (DL_TimerG_ClockConfig *) &gTIMER_0ClockConfig);

    DL_TimerG_initTimerMode(TIMER_0_INST,
        (DL_TimerG_TimerConfig *) &gTIMER_0TimerConfig);
    DL_TimerG_enableInterrupt(TIMER_0_INST , DL_TIMERG_INTERRUPT_ZERO_EVENT);
	NVIC_SetPriority(TIMER_0_INST_INT_IRQN, 2);
    DL_TimerG_enableClock(TIMER_0_INST);





}



static const DL_UART_Main_ClockConfig gUART_0ClockConfig = {
    .clockSel    = DL_UART_MAIN_CLOCK_BUSCLK,
    .divideRatio = DL_UART_MAIN_CLOCK_DIVIDE_RATIO_1
};

static const DL_UART_Main_Config gUART_0Config = {
    .mode        = DL_UART_MAIN_MODE_NORMAL,
    .direction   = DL_UART_MAIN_DIRECTION_TX_RX,
    .flowControl = DL_UART_MAIN_FLOW_CONTROL_NONE,
    .parity      = DL_UART_MAIN_PARITY_NONE,
    .wordLength  = DL_UART_MAIN_WORD_LENGTH_8_BITS,
    .stopBits    = DL_UART_MAIN_STOP_BITS_ONE
};

SYSCONFIG_WEAK void SYSCFG_DL_UART_0_init(void)
{
    DL_UART_Main_setClockConfig(UART_0_INST, (DL_UART_Main_ClockConfig *) &gUART_0ClockConfig);

    DL_UART_Main_init(UART_0_INST, (DL_UART_Main_Config *) &gUART_0Config);
    /*
     * Configure baud rate by setting oversampling and baud rate divisors.
     *  Target baud rate: 9600
     *  Actual baud rate: 9600.24
     */
    DL_UART_Main_setOversampling(UART_0_INST, DL_UART_OVERSAMPLING_RATE_16X);
    DL_UART_Main_setBaudRateDivisor(UART_0_INST, UART_0_IBRD_32_MHZ_9600_BAUD, UART_0_FBRD_32_MHZ_9600_BAUD);



    DL_UART_Main_enable(UART_0_INST);
}

static const DL_SPI_Config gTFT_SPI_config = {
    .mode        = DL_SPI_MODE_CONTROLLER,
    .frameFormat = DL_SPI_FRAME_FORMAT_MOTO3_POL0_PHA0,
    .parity      = DL_SPI_PARITY_NONE,
    .dataSize    = DL_SPI_DATA_SIZE_8,
    .bitOrder    = DL_SPI_BIT_ORDER_MSB_FIRST,
};

static const DL_SPI_ClockConfig gTFT_SPI_clockConfig = {
    .clockSel    = DL_SPI_CLOCK_BUSCLK,
    .divideRatio = DL_SPI_CLOCK_DIVIDE_RATIO_1
};

SYSCONFIG_WEAK void SYSCFG_DL_TFT_SPI_init(void) {
    DL_SPI_setClockConfig(TFT_SPI_INST, (DL_SPI_ClockConfig *) &gTFT_SPI_clockConfig);

    DL_SPI_init(TFT_SPI_INST, (DL_SPI_Config *) &gTFT_SPI_config);

    /* Configure Controller mode */
    /*
     * Set the bit rate clock divider to generate the serial output clock
     *     outputBitRate = (spiInputClock) / ((1 + SCR) * 2)
     *     8000000 = (32000000)/((1 + 1) * 2)
     */
    DL_SPI_setBitRateSerialClockDivider(TFT_SPI_INST, 1);
    /* Set RX and TX FIFO threshold levels */
    DL_SPI_setFIFOThreshold(TFT_SPI_INST, DL_SPI_RX_FIFO_LEVEL_1_2_FULL, DL_SPI_TX_FIFO_LEVEL_1_2_EMPTY);

    /* Enable module */
    DL_SPI_enable(TFT_SPI_INST);
}
static const DL_SPI_Config gSPI_LDC_config = {
    .mode        = DL_SPI_MODE_CONTROLLER,
    .frameFormat = DL_SPI_FRAME_FORMAT_MOTO3_POL1_PHA1,
    .parity      = DL_SPI_PARITY_NONE,
    .dataSize    = DL_SPI_DATA_SIZE_8,
    .bitOrder    = DL_SPI_BIT_ORDER_MSB_FIRST,
};

static const DL_SPI_ClockConfig gSPI_LDC_clockConfig = {
    .clockSel    = DL_SPI_CLOCK_BUSCLK,
    .divideRatio = DL_SPI_CLOCK_DIVIDE_RATIO_1
};

SYSCONFIG_WEAK void SYSCFG_DL_SPI_LDC_init(void) {
    DL_SPI_setClockConfig(SPI_LDC_INST, (DL_SPI_ClockConfig *) &gSPI_LDC_clockConfig);

    DL_SPI_init(SPI_LDC_INST, (DL_SPI_Config *) &gSPI_LDC_config);

    /* Configure Controller mode */
    /*
     * Set the bit rate clock divider to generate the serial output clock
     *     outputBitRate = (spiInputClock) / ((1 + SCR) * 2)
     *     1000000 = (32000000)/((1 + 15) * 2)
     */
    DL_SPI_setBitRateSerialClockDivider(SPI_LDC_INST, 15);
    /* Set RX and TX FIFO threshold levels */
    DL_SPI_setFIFOThreshold(SPI_LDC_INST, DL_SPI_RX_FIFO_LEVEL_1_2_FULL, DL_SPI_TX_FIFO_LEVEL_1_2_EMPTY);

    /* Enable module */
    DL_SPI_enable(SPI_LDC_INST);
}

SYSCONFIG_WEAK void SYSCFG_DL_SYSTICK_init(void)
{
    /*
     * Initializes the SysTick period to 1.00 ms,
     * enables the interrupt, and starts the SysTick Timer
     */
    DL_SYSTICK_config(32000);
}

