#ifndef __BIT_H
#define __BIT_H
/**********************************************************************************
	Copyright (C) 2016 SOL.lab <maxwellxyao@foxmail.com>

*File name:		bit.h
*Description:	����λ�������ο�GRBL
*Author:		MaxwellXyao
*Version:		V0.0.20160626
*Date:			2016-6-26 03:04:55
*History:		
[2016-6-26]	�ļ�����;

**********************************************************************************/


#define BIT(n) 					(1 << n) 				//λmask
#define bit_SetTrue(x,mask) 	(x |= mask)				//��λ����Ϊ��
#define bit_SetFalse(x,mask)	(x &= ~mask)			//��λ����Ϊ��
#define bit_Toggle(x,mask) 		(x ^= mask)				//λ�л�
#define bit_IsTrue(x,mask) 		((x & mask) != 0)		//��λ�Ƿ���
#define bit_IsFalse(x,mask) 	((x & mask) == 0)		//��λ�Ƿ��

#endif

