#include "ldc1000.h"

volatile uint32_t ProximityData = 0;
volatile uint32_t FrequencyData = 0;

/******************** SPI 底层读写 ********************/
uint8_t SPI_LDC_RW(uint8_t dat)
{
    uint8_t data = 0;

    //发送数据
    DL_SPI_transmitData8(SPI_LDC_INST,dat);
    //等待SPI总线空闲
    while(DL_SPI_isBusy(SPI_LDC_INST));
    //接收数据
    data = DL_SPI_receiveData8(SPI_LDC_INST);
    //等待SPI总线空闲
    while(DL_SPI_isBusy(SPI_LDC_INST));
    return data;
}

/******************** 寄存器操作 ********************/
void LDC1000_WriteReg(uint8_t reg, uint8_t data)
{
    CSB_LOW();
    SPI_LDC_RW(reg);
    SPI_LDC_RW(data);
    CSB_HIGH();
}

uint8_t LDC1000_ReadReg(uint8_t reg)
{
    uint8_t Reg_Value;

    CSB_LOW();//拉低csn片选信号，使能LDC的spi传输

    SPI_LDC_RW(reg|SPI_RWBIT);//选择寄存器
	Reg_Value = SPI_LDC_RW(SPI_NOP);

    CSB_HIGH();//拉高csn片选信号，即释放LDC的spi传输完毕；

    return Reg_Value;
}

/******************** 初始化函数 ********************/
void LDC1000_Init(void)
{
    // 配置LDC1000寄存器
    LDC1000_WriteReg(LDC1000_RPMAX, 0x09);
    LDC1000_WriteReg(LDC1000_RPMIN, 0x37);
    LDC1000_WriteReg(LDC1000_SENSORFREQ, 0xE2);
    LDC1000_WriteReg(LDC1000_LDCCONFIG, 0x17);
    LDC1000_WriteReg(LDC1000_CLKCONFIG, 0x00);
    LDC1000_WriteReg(LDC1000_THRESHILSB, 0x50);
    LDC1000_WriteReg(LDC1000_THRESHIMSB, 0x14);
    LDC1000_WriteReg(LDC1000_THRESLOLSB, 0xC0);
    LDC1000_WriteReg(LDC1000_THRESLOMSB, 0x12);
    LDC1000_WriteReg(LDC1000_INTCONFIG, 0x02);
    LDC1000_WriteReg(LDC1000_PWRCONFIG, 0x01);
}

/******************** 数据读取函数 ********************/
void LDC1000_ReadData(void)
{
    ProximityData = 0;
    FrequencyData = 0;

    // 等待INTB变低（数据就绪）
    while(INTB_READ()!= 0);
    ProximityData  = LDC1000_ReadReg(LDC1000_PROXLSB);
    while(INTB_READ()!= 0);
    ProximityData |= LDC1000_ReadReg(LDC1000_PROXMSB) << 8;
//    while(INTB_READ()!= 0);
//    FrequencyData  = LDC1000_ReadReg(LDC1000_FREQCTRLSB);
//    while(INTB_READ()!= 0);
//    FrequencyData |= LDC1000_ReadReg(LDC1000_FREQCTRMID) << 8;
//    while(INTB_READ()!= 0);
//    FrequencyData |= LDC1000_ReadReg(LDC1000_FREQCTRMSB) << 16;
}

//void LDC_Delay_1ms(uint32_t time)
//{
//   uint16_t i=0;
//   while(time--)
//   {
//      i=12000;  //自己定义
//      while(i--) ;
//   }
//}
