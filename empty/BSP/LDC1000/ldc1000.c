#include "ldc1000.h"

volatile uint32_t ProximityData = 0;
volatile uint32_t FrequencyData = 0;

/******************** SPI �ײ��д ********************/
uint8_t SPI_LDC_RW(uint8_t dat)
{
    uint8_t data = 0;

    //��������
    DL_SPI_transmitData8(SPI_LDC_INST,dat);
    //�ȴ�SPI���߿���
    while(DL_SPI_isBusy(SPI_LDC_INST));
    //��������
    data = DL_SPI_receiveData8(SPI_LDC_INST);
    //�ȴ�SPI���߿���
    while(DL_SPI_isBusy(SPI_LDC_INST));
    return data;
}

/******************** �Ĵ������� ********************/
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

    CSB_LOW();//����csnƬѡ�źţ�ʹ��LDC��spi����

    SPI_LDC_RW(reg|SPI_RWBIT);//ѡ��Ĵ���
	Reg_Value = SPI_LDC_RW(SPI_NOP);

    CSB_HIGH();//����csnƬѡ�źţ����ͷ�LDC��spi������ϣ�

    return Reg_Value;
}

/******************** ��ʼ������ ********************/
void LDC1000_Init(void)
{
    // ����LDC1000�Ĵ���
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

/******************** ���ݶ�ȡ���� ********************/
void LDC1000_ReadData(void)
{
    ProximityData = 0;
    FrequencyData = 0;

    // �ȴ�INTB��ͣ����ݾ�����
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
//      i=12000;  //�Լ�����
//      while(i--) ;
//   }
//}
