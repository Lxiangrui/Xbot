/**********************************************************************************
	Copyright (C) 2016 SOL.lab <maxwellxyao@foxmail.com>

*File name:		spi.h
*Description:	ģ��spiЭ��
*Author:		MaxwellXyao
*Version:		V0.0.20160626
*Date:			2016-6-26 17:21:17
*History:		
[2016-6-26]	�ļ�����;

**********************************************************************************/
#include "simuspi.h"		//ģ��SPIЭ��

//###########################��������###########################
/*****************************************************************
*Function:	SimuSPI_ReadWriteByte
*Description:	ģ��SPIЭ��ʵ��
*Input:			ģ��SPI�ṹ�壬���͵��ַ�
*Output:		���յ��ַ�
*Other:		
*****************************************************************/
unsigned char SimuSPI_ReadWriteByte(SimuSPI *SimuSPI_Struct,unsigned char data)   
{   
    unsigned char i=0;   
    unsigned char temp=0;

	SimuSPI_Struct->PinSetSCLK(0);   
    for(i=0;i<8;i++)   
    {   
        if(data&0x80)SimuSPI_Struct->PinSetMOSI(1);   
        else SimuSPI_Struct->PinSetMOSI(0);   
        data<<=1;   
        SimuSPI_Struct->PinSetSCLK(1);  
        SimuSPI_Struct->Delayus(SimuSPI_Struct->IntervalTime);  
        temp<<=1;   
        if(SimuSPI_Struct->PinGetMISO())temp++;   
		SimuSPI_Struct->Delayus(SimuSPI_Struct->IntervalTime);  
        SimuSPI_Struct->PinSetSCLK(0);   
    }   
    return temp;   
}

/*****************************************************************
*Function:	SetIntTime
*Description:	ģ��SPI�ṹ�壬ģ��SPI��ʱ��������
*Input:		��ʱ���ȣ�us��
*Output:	��
*Other:		
*****************************************************************/
void SimuSPI_SetIntTime(SimuSPI *SimuSPI_Struct,unsigned int IntTime)
{
	SimuSPI_Struct->IntervalTime=IntTime;	
}



