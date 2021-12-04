#ifndef __SIMUSPI_H
#define __SIMUSPI_H

/**********************************************************************************
	Copyright (C) 2016 SOL.lab <maxwellxyao@foxmail.com>

*File name:		simuspi.h
*Description:	ģ��spiЭ��
*Author:		MaxwellXyao
*Version:		V0.0.20160626
*Date:			2016-6-26 17:21:17
*History:		
[2016-6-26]	�ļ�����;

**********************************************************************************/

//###########################�����塿###########################
typedef struct _SimuSPI{		//SPI�ӿ�����
	void (*PinSetMOSI)(unsigned char);	//MOSI�������õ�ƽ����
	void (*PinSetSCLK)(unsigned char);	//SCLK�������õ�ƽ����
	unsigned char (*PinGetMISO)();		//MISO���Ŷ�ȡ��ƽ����
	void (*Delayus)(unsigned int);		//us��ʱ����
	unsigned int IntervalTime;			//��ʱʱ��(us)
}SimuSPI;			

//###########################��API��###########################
unsigned char SimuSPI_ReadWriteByte(SimuSPI *SimuSPI_Struct,unsigned char data);		//ģ��SPI�����ַ�
void SimuSPI_SetIntTime(SimuSPI *SimuSPI_Struct,unsigned int IntTime);			//ģ��SPI�����ٶ�

/*
��ʹ��˵����	ģ��SPIЭ��
�����û����ٹ���ģ��SPIЭ��㡣ֻ���ڶ���Ľṹ��������
IO�ڲ�����������ʱ�������ɵ���API��ʵ��SPIЭ�顣

����ļ�����ȫ������Ӳ���ģ����Կ�����ֲ���κε�Ƭ�����κ������ϡ�

ʹ�÷�����
1.����ṹ�壬����ʼ������Ա������

SimuSPI W25QXX;
void W25QXX_SPI_Init(void)
{
	GPIO_Init();
	Delay_Init();	

	W25QXX.PinSetMOSI=writePA10;
	W25QXX.PinSetSCLK=writePA11;
	W25QXX.PinGetMISO=readPA12;
	W25QXX.Delayus=delay_us;
	W25QXX.IntervalTime=5;	
}

2.ʹ��SimuSPIģ��SPIЭ��

void SPI_FLASH_Write_SR(u8 sr)   
{   
	SPI_FLASH_CS=0;                            //ʹ������   
	SimuSPI_ReadWriteByte(&W25QXX,W25X_WriteStatusReg);   //����дȡ״̬�Ĵ�������    
	SimuSPI_ReadWriteByte(&W25QXX,sr);               //д��һ���ֽ�  
	SPI_FLASH_CS=1;                            //ȡ��Ƭѡ     	      
}


[ע��]��CS������Ҫ�û����ж��壬�����SimuSPIʹ�á�   





*/


#endif

