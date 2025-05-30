/*
 * Copyright (c) 2023, Texas Instruments Incorporated - http://www.ti.com
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
 *  ============ ti_msp_dl_config.h =============
 *  Configured MSPM0 DriverLib module declarations
 *
 *  DO NOT EDIT - This file is generated for the MSPM0G350X
 *  by the SysConfig tool.
 */
#ifndef ti_msp_dl_config_h
#define ti_msp_dl_config_h

#define CONFIG_MSPM0G350X
#define CONFIG_MSPM0G3507

#if defined(__ti_version__) || defined(__TI_COMPILER_VERSION__)
#define SYSCONFIG_WEAK __attribute__((weak))
#elif defined(__IAR_SYSTEMS_ICC__)
#define SYSCONFIG_WEAK __weak
#elif defined(__GNUC__)
#define SYSCONFIG_WEAK __attribute__((weak))
#endif

#include <ti/devices/msp/msp.h>
#include <ti/driverlib/driverlib.h>
#include <ti/driverlib/m0p/dl_core.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  ======== SYSCFG_DL_init ========
 *  Perform all required MSP DL initialization
 *
 *  This function should be called once at a point before any use of
 *  MSP DL.
 */


/* clang-format off */

#define POWER_STARTUP_DELAY                                                (16)



#define CPUCLK_FREQ                                                     32000000



/* Defines for TB6612_PWM */
#define TB6612_PWM_INST                                                    TIMA1
#define TB6612_PWM_INST_IRQHandler                              TIMA1_IRQHandler
#define TB6612_PWM_INST_INT_IRQN                                (TIMA1_INT_IRQn)
#define TB6612_PWM_INST_CLK_FREQ                                         1000000
/* GPIO defines for channel 0 */
#define GPIO_TB6612_PWM_C0_PORT                                            GPIOA
#define GPIO_TB6612_PWM_C0_PIN                                    DL_GPIO_PIN_17
#define GPIO_TB6612_PWM_C0_IOMUX                                 (IOMUX_PINCM39)
#define GPIO_TB6612_PWM_C0_IOMUX_FUNC                IOMUX_PINCM39_PF_TIMA1_CCP0
#define GPIO_TB6612_PWM_C0_IDX                               DL_TIMER_CC_0_INDEX
/* GPIO defines for channel 1 */
#define GPIO_TB6612_PWM_C1_PORT                                            GPIOA
#define GPIO_TB6612_PWM_C1_PIN                                    DL_GPIO_PIN_16
#define GPIO_TB6612_PWM_C1_IOMUX                                 (IOMUX_PINCM38)
#define GPIO_TB6612_PWM_C1_IOMUX_FUNC                IOMUX_PINCM38_PF_TIMA1_CCP1
#define GPIO_TB6612_PWM_C1_IDX                               DL_TIMER_CC_1_INDEX

/* Defines for LDC_CLK */
#define LDC_CLK_INST                                                       TIMG6
#define LDC_CLK_INST_IRQHandler                                 TIMG6_IRQHandler
#define LDC_CLK_INST_INT_IRQN                                   (TIMG6_INT_IRQn)
#define LDC_CLK_INST_CLK_FREQ                                           32000000
/* GPIO defines for channel 0 */
#define GPIO_LDC_CLK_C0_PORT                                               GPIOB
#define GPIO_LDC_CLK_C0_PIN                                        DL_GPIO_PIN_2
#define GPIO_LDC_CLK_C0_IOMUX                                    (IOMUX_PINCM15)
#define GPIO_LDC_CLK_C0_IOMUX_FUNC                   IOMUX_PINCM15_PF_TIMG6_CCP0
#define GPIO_LDC_CLK_C0_IDX                                  DL_TIMER_CC_0_INDEX

/* Defines for SERVO */
#define SERVO_INST                                                         TIMG8
#define SERVO_INST_IRQHandler                                   TIMG8_IRQHandler
#define SERVO_INST_INT_IRQN                                     (TIMG8_INT_IRQn)
#define SERVO_INST_CLK_FREQ                                              1000000
/* GPIO defines for channel 0 */
#define GPIO_SERVO_C0_PORT                                                 GPIOA
#define GPIO_SERVO_C0_PIN                                          DL_GPIO_PIN_1
#define GPIO_SERVO_C0_IOMUX                                       (IOMUX_PINCM2)
#define GPIO_SERVO_C0_IOMUX_FUNC                      IOMUX_PINCM2_PF_TIMG8_CCP0
#define GPIO_SERVO_C0_IDX                                    DL_TIMER_CC_0_INDEX



/* Defines for TIMER_0 */
#define TIMER_0_INST                                                     (TIMG0)
#define TIMER_0_INST_IRQHandler                                 TIMG0_IRQHandler
#define TIMER_0_INST_INT_IRQN                                   (TIMG0_INT_IRQn)
#define TIMER_0_INST_LOAD_VALUE                                           (999U)



/* Defines for UART_0 */
#define UART_0_INST                                                        UART0
#define UART_0_INST_FREQUENCY                                           32000000
#define UART_0_INST_IRQHandler                                  UART0_IRQHandler
#define UART_0_INST_INT_IRQN                                      UART0_INT_IRQn
#define GPIO_UART_0_RX_PORT                                                GPIOA
#define GPIO_UART_0_TX_PORT                                                GPIOA
#define GPIO_UART_0_RX_PIN                                        DL_GPIO_PIN_11
#define GPIO_UART_0_TX_PIN                                        DL_GPIO_PIN_10
#define GPIO_UART_0_IOMUX_RX                                     (IOMUX_PINCM22)
#define GPIO_UART_0_IOMUX_TX                                     (IOMUX_PINCM21)
#define GPIO_UART_0_IOMUX_RX_FUNC                      IOMUX_PINCM22_PF_UART0_RX
#define GPIO_UART_0_IOMUX_TX_FUNC                      IOMUX_PINCM21_PF_UART0_TX
#define UART_0_BAUD_RATE                                                  (9600)
#define UART_0_IBRD_32_MHZ_9600_BAUD                                       (208)
#define UART_0_FBRD_32_MHZ_9600_BAUD                                        (21)




/* Defines for TFT_SPI */
#define TFT_SPI_INST                                                       SPI1
#define TFT_SPI_INST_IRQHandler                                 SPI1_IRQHandler
#define TFT_SPI_INST_INT_IRQN                                     SPI1_INT_IRQn
#define GPIO_TFT_SPI_PICO_PORT                                            GPIOB
#define GPIO_TFT_SPI_PICO_PIN                                     DL_GPIO_PIN_8
#define GPIO_TFT_SPI_IOMUX_PICO                                 (IOMUX_PINCM25)
#define GPIO_TFT_SPI_IOMUX_PICO_FUNC                 IOMUX_PINCM25_PF_SPI1_PICO
#define GPIO_TFT_SPI_POCI_PORT                                            GPIOB
#define GPIO_TFT_SPI_POCI_PIN                                    DL_GPIO_PIN_21
#define GPIO_TFT_SPI_IOMUX_POCI                                 (IOMUX_PINCM49)
#define GPIO_TFT_SPI_IOMUX_POCI_FUNC                 IOMUX_PINCM49_PF_SPI1_POCI
/* GPIO configuration for TFT_SPI */
#define GPIO_TFT_SPI_SCLK_PORT                                            GPIOB
#define GPIO_TFT_SPI_SCLK_PIN                                     DL_GPIO_PIN_9
#define GPIO_TFT_SPI_IOMUX_SCLK                                 (IOMUX_PINCM26)
#define GPIO_TFT_SPI_IOMUX_SCLK_FUNC                 IOMUX_PINCM26_PF_SPI1_SCLK
/* Defines for SPI_LDC */
#define SPI_LDC_INST                                                       SPI0
#define SPI_LDC_INST_IRQHandler                                 SPI0_IRQHandler
#define SPI_LDC_INST_INT_IRQN                                     SPI0_INT_IRQn
#define GPIO_SPI_LDC_PICO_PORT                                            GPIOB
#define GPIO_SPI_LDC_PICO_PIN                                    DL_GPIO_PIN_17
#define GPIO_SPI_LDC_IOMUX_PICO                                 (IOMUX_PINCM43)
#define GPIO_SPI_LDC_IOMUX_PICO_FUNC                 IOMUX_PINCM43_PF_SPI0_PICO
#define GPIO_SPI_LDC_POCI_PORT                                            GPIOB
#define GPIO_SPI_LDC_POCI_PIN                                    DL_GPIO_PIN_19
#define GPIO_SPI_LDC_IOMUX_POCI                                 (IOMUX_PINCM45)
#define GPIO_SPI_LDC_IOMUX_POCI_FUNC                 IOMUX_PINCM45_PF_SPI0_POCI
/* GPIO configuration for SPI_LDC */
#define GPIO_SPI_LDC_SCLK_PORT                                            GPIOB
#define GPIO_SPI_LDC_SCLK_PIN                                    DL_GPIO_PIN_18
#define GPIO_SPI_LDC_IOMUX_SCLK                                 (IOMUX_PINCM44)
#define GPIO_SPI_LDC_IOMUX_SCLK_FUNC                 IOMUX_PINCM44_PF_SPI0_SCLK



/* Port definition for Pin Group BUZZER */
#define BUZZER_PORT                                                      (GPIOB)

/* Defines for IO: GPIOB.27 with pinCMx 58 on package pin 29 */
#define BUZZER_IO_PIN                                           (DL_GPIO_PIN_27)
#define BUZZER_IO_IOMUX                                          (IOMUX_PINCM58)
/* Port definition for Pin Group TFT */
#define TFT_PORT                                                         (GPIOB)

/* Defines for RES: GPIOB.10 with pinCMx 27 on package pin 62 */
#define TFT_RES_PIN                                             (DL_GPIO_PIN_10)
#define TFT_RES_IOMUX                                            (IOMUX_PINCM27)
/* Defines for DC: GPIOB.11 with pinCMx 28 on package pin 63 */
#define TFT_DC_PIN                                              (DL_GPIO_PIN_11)
#define TFT_DC_IOMUX                                             (IOMUX_PINCM28)
/* Defines for CS: GPIOB.14 with pinCMx 31 on package pin 2 */
#define TFT_CS_PIN                                              (DL_GPIO_PIN_14)
#define TFT_CS_IOMUX                                             (IOMUX_PINCM31)
/* Defines for BLK: GPIOB.26 with pinCMx 57 on package pin 28 */
#define TFT_BLK_PIN                                             (DL_GPIO_PIN_26)
#define TFT_BLK_IOMUX                                            (IOMUX_PINCM57)
/* Port definition for Pin Group ENCODER */
#define ENCODER_PORT                                                     (GPIOB)

/* Defines for LA: GPIOB.15 with pinCMx 32 on package pin 3 */
// pins affected by this interrupt request:["LA","LB","RA","RB"]
#define ENCODER_INT_IRQN                                        (GPIOB_INT_IRQn)
#define ENCODER_INT_IIDX                        (DL_INTERRUPT_GROUP1_IIDX_GPIOB)
#define ENCODER_LA_IIDX                                     (DL_GPIO_IIDX_DIO15)
#define ENCODER_LA_PIN                                          (DL_GPIO_PIN_15)
#define ENCODER_LA_IOMUX                                         (IOMUX_PINCM32)
/* Defines for LB: GPIOB.16 with pinCMx 33 on package pin 4 */
#define ENCODER_LB_IIDX                                     (DL_GPIO_IIDX_DIO16)
#define ENCODER_LB_PIN                                          (DL_GPIO_PIN_16)
#define ENCODER_LB_IOMUX                                         (IOMUX_PINCM33)
/* Defines for RA: GPIOB.6 with pinCMx 23 on package pin 58 */
#define ENCODER_RA_IIDX                                      (DL_GPIO_IIDX_DIO6)
#define ENCODER_RA_PIN                                           (DL_GPIO_PIN_6)
#define ENCODER_RA_IOMUX                                         (IOMUX_PINCM23)
/* Defines for RB: GPIOB.7 with pinCMx 24 on package pin 59 */
#define ENCODER_RB_IIDX                                      (DL_GPIO_IIDX_DIO7)
#define ENCODER_RB_PIN                                           (DL_GPIO_PIN_7)
#define ENCODER_RB_IOMUX                                         (IOMUX_PINCM24)
/* Port definition for Pin Group TB6612_A */
#define TB6612_A_PORT                                                    (GPIOA)

/* Defines for AIN1: GPIOA.14 with pinCMx 36 on package pin 7 */
#define TB6612_A_AIN1_PIN                                       (DL_GPIO_PIN_14)
#define TB6612_A_AIN1_IOMUX                                      (IOMUX_PINCM36)
/* Defines for AIN2: GPIOA.15 with pinCMx 37 on package pin 8 */
#define TB6612_A_AIN2_PIN                                       (DL_GPIO_PIN_15)
#define TB6612_A_AIN2_IOMUX                                      (IOMUX_PINCM37)
/* Port definition for Pin Group TB6612_B */
#define TB6612_B_PORT                                                    (GPIOB)

/* Defines for BIN1: GPIOB.12 with pinCMx 29 on package pin 64 */
#define TB6612_B_BIN1_PIN                                       (DL_GPIO_PIN_12)
#define TB6612_B_BIN1_IOMUX                                      (IOMUX_PINCM29)
/* Defines for BIN2: GPIOB.13 with pinCMx 30 on package pin 1 */
#define TB6612_B_BIN2_PIN                                       (DL_GPIO_PIN_13)
#define TB6612_B_BIN2_IOMUX                                      (IOMUX_PINCM30)
/* Defines for CSB: GPIOA.8 with pinCMx 19 on package pin 54 */
#define LDC_CSB_PORT                                                     (GPIOA)
#define LDC_CSB_PIN                                              (DL_GPIO_PIN_8)
#define LDC_CSB_IOMUX                                            (IOMUX_PINCM19)
/* Defines for INTB: GPIOB.3 with pinCMx 16 on package pin 51 */
#define LDC_INTB_PORT                                                    (GPIOB)
#define LDC_INTB_PIN                                             (DL_GPIO_PIN_3)
#define LDC_INTB_IOMUX                                           (IOMUX_PINCM16)



/* clang-format on */

void SYSCFG_DL_init(void);
void SYSCFG_DL_initPower(void);
void SYSCFG_DL_GPIO_init(void);
void SYSCFG_DL_SYSCTL_init(void);
void SYSCFG_DL_TB6612_PWM_init(void);
void SYSCFG_DL_LDC_CLK_init(void);
void SYSCFG_DL_SERVO_init(void);
void SYSCFG_DL_TIMER_0_init(void);
void SYSCFG_DL_UART_0_init(void);
void SYSCFG_DL_TFT_SPI_init(void);
void SYSCFG_DL_SPI_LDC_init(void);

void SYSCFG_DL_SYSTICK_init(void);

bool SYSCFG_DL_saveConfiguration(void);
bool SYSCFG_DL_restoreConfiguration(void);

#ifdef __cplusplus
}
#endif

#endif /* ti_msp_dl_config_h */
