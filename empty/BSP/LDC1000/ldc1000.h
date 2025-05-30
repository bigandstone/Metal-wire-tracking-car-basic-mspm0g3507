#ifndef __LDC1000_H__
#define __LDC1000_H__

#include <stdint.h>
#include "ti_msp_dl_config.h"

#define CSB_HIGH()      DL_GPIO_setPins(LDC_CSB_PORT, LDC_CSB_PIN)
#define CSB_LOW()       DL_GPIO_clearPins(LDC_CSB_PORT, LDC_CSB_PIN)
#define INTB_READ()     DL_GPIO_readPins(LDC_INTB_PORT, LDC_INTB_PIN)

#define SPI_RWBIT 		0x80
#define SPI_NOP         0XFF//¿ÕÖ¸ÁîÓÃÀ´¶Á×´Ì¬¼Ä´æÆ÷
/****************¼Ä´æÆ÷µØÖ·Çø*******************/
#define LDC1000_REVID        0x00
#define LDC1000_RPMAX        0x01
#define LDC1000_RPMIN        0x02
#define LDC1000_SENSORFREQ   0x03
#define LDC1000_LDCCONFIG    0x04
#define LDC1000_CLKCONFIG    0x05
#define LDC1000_THRESHILSB   0x06
#define LDC1000_THRESHIMSB   0x07
#define LDC1000_THRESLOLSB   0x08
#define LDC1000_THRESLOMSB   0x09
#define LDC1000_INTCONFIG    0x0A
#define LDC1000_PWRCONFIG    0x0B
#define LDC1000_STATUS       0x20
#define LDC1000_PROXLSB      0x21
#define LDC1000_PROXMSB      0x22
#define LDC1000_FREQCTRLSB   0x23
#define LDC1000_FREQCTRMID   0x24
#define LDC1000_FREQCTRMSB   0x25

// LDC BITMASKS
#define LDC1000_BIT_AMPLITUDE    0x18
#define LDC1000_BIT_RESPTIME     0x07
#define LDC1000_BIT_CLKSEL       0x02
#define LDC1000_BIT_CLKPD        0x01
#define LDC1000_BIT_INTMODE      0x07
#define LDC1000_BIT_PWRMODE      0x01
#define LDC1000_BIT_STATUSOSC    0x80
#define LDC1000_BIT_STATUSDRDYB  0x40
#define LDC1000_BIT_STATUSWAKEUP 0x20
#define LDC1000_BIT_STATUSCOMP   0x10

#define TEST_RPMAX_MAX 	0x13			  /**< maximum calibration value for RPMAX */
#define TEST_RPMAX_MIN 	0x10			  /**< minimum calibration value for RPMAX */
#define TEST_RPMAX_INIT TEST_RPMAX_MIN+1  /**< RPMAX initial value */
#define TEST_RPMIN_MAX 	0x3D   			  /**< maximum calibration value for RPMIN */
#define TEST_RPMIN_MIN 	0x3A    		  /**< minimum calibration value for RPMIN */
#define TEST_RPMIN_INIT TEST_RPMIN_MIN+1  /**< RPMIN initial value */

// Final Test Range
#define TEST_RP_MSB_MAX 0x12	/**< maximum value for proximity data */
#define TEST_RP_MSB_MIN 0x0A	/**< minimum value for proximity data */
#define TEST_FC_MAX 0x0D5D		/**< maximum value for frequency counter */
#define TEST_FC_MIN 0x0D39		/**< minimum value for frequency counter */

extern volatile uint32_t ProximityData;
extern volatile uint32_t FrequencyData;

void LDC1000_Init(void);
void LDC1000_ReadData(void);
uint8_t LDC1000_ReadReg(uint8_t reg);
void LDC1000_WriteReg(uint8_t reg, uint8_t data);

#endif