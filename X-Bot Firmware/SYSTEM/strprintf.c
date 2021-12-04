/**********************************************************************************
	Copyright (C) 2016 SOL.lab <maxwellxyao@foxmail.com>

*File name:		strprintf.c
*Description:	��ʽ���ַ����˺���
*Author:		MaxwellXyao
*Version:		V0.0.20160626
*Date:			2016-6-26 02:40:29
*History:		
[2016-6-26]	�ļ�����;

**********************************************************************************/
#include "strprintf.h"
#include<stdarg.h> 	
	

//###########################��������###########################

/*****************************************************************
*Function:		_strprintf
*Description:	��ʽ���ַ����ˣ��ο�FATFS0.09a��ff.c��f_printf()������
*Input:			���豸����ַ�����ָ�룬
				��ʽ���ַ�����
				�䳤�������ݱ���
*Output:		��
*Other:			���뱻ʹ�ñ䳤�����ĿǺ������ã��Ǻ������û�����
******************************************************************/
void _strprintf(void (*myputc)(char),const char* str,va_list arp)		//sprintf�˺������豻���б䳤�����ĺ������ã�
{
	unsigned char f,r,fl=0,l=3,lt,jj;		//Ĭ����3λС��,С������0~7λ
	unsigned char i,j,w,lp;
	unsigned long v;
	char c, d, s[16], *p;
	int res, chc, cc,ll;
	int kh,kl,pow=1;																
	double k;

	for (cc=res=0;cc!=-1;res+=cc) 		   			//������ʽ���ַ����������
	{
		c = *str++;						   			//ÿһ��ȡһ���ַ�
//---------------------------------//��ȡ��'\0',��������
		if (c == 0) break;					
//---------------------------------//��ȡ����'%'����ʱ
		if (c != '%') {						
			myputc(c);									
			continue;
		}
//---------------------------------//��ȡ��'%'����ʱ
		w=f=0;
		k=0;
		lp=0;
		c=*str++;				   					//Խ��'%'�������ʽ
		if (c == '0') {								//%0��0���
			f = 1; c = *str++;						//f0�����λ��1����ȡ��һ���ַ�
		} 
		else if (c == '-') {							//%-������루�����ո�
				f = 2; c = *str++;					//f�������λ��1����ȡ��һ���ַ�
			}
		else if (c == '.') {						//%.3f��ʾ��3λС��
			fl=1;c=*str++;
		}

		while (((c)>='0')&&((c)<='9')) {			//"%030"����30ת��Ϊ����
			if(fl==1){
				lp=lp*10+c-'0';		
				c=*str++;
			}
			else{
				w=w*10+c-'0';		
				c=*str++;
			}								//�����ֶ���
		}
		if(fl==1) l=(lp>7)? 7:lp;
		if (c == 'l' || c == 'L') {					//%ld�ȳ�����
			f |= 4; c = *str++;		 				//f���α��λ��1������һ���ַ�
		}
		if (!c) break;								//�����ʱ���ַ����������
//---------------------------------//�����ʽ����ʶ����d,s,c,x,o,f��
		d = c;						
		if (((c)>='a')&&((c)<='z')) d -= 0x20;		//�����Сд������ɴ�д����
		switch (d) {								//����%*�����

		case 'S' :					/* String */
			p = va_arg(arp,char*);					//ȡ�ַ�������
			for(j=0;p[j];j++);						//���ȼ���
			ll=j;
			chc = 0;
			if (!(f&2)) {							//��������룬��߾�Ҫ���ո�%06s
				while (j++ < w) 
				{
					myputc(' ');
					chc+=1;					
				}
			}

			jj=0;	
			while (p[jj]!='\0')
			{		
				myputc(p[jj]);										
				jj++;
			}
											
			chc+=ll;
			while (j++ < w) 						//����룬��߾Ͳ��ÿո��ұ���ո�%-06s
			{
				myputc(' ');
				chc+=1;						
			}	 
			cc = chc;
			continue;

		case 'C' :
		{					/* Character */
			myputc((char)va_arg(arp,int));	continue;
		}

		case 'F' :											//Ĭ�ϱ���3λС��
		{													/* double(64λ)/float(32λ) */												
			k=va_arg(arp,double);
			if(k<0){
				l|=8;
				k*=-1;										//�����õ�λ1
			}
			kh=(int)k;										//����С������
			pow=1;
			lt=l&7;
			while((lt-1)>=0){
				pow*=10;
				lt--;
			}
			kl=(int)(pow*(k-kh));				
			i=0;

			lt=l&7;
			while(lt--){												//����С������
				if(kl){
					d=(char)(kl%10);							//��10����ȡ�࣬��ȡ��λ������Ϊ�ַ�����
					kl/=10;										//�ݽ�								
					s[i++]='0'+d;								//�������s
				}
				else s[i++]='0';
			}

			s[i++]='.';										//����С����
			do{												//������������
				d=(char)(kh%10);								//��10����ȡ�࣬��ȡ��λ������Ϊ�ַ�����
				kh/=10;										//�ݽ�
				s[i++]='0'+d;								//�������s
			}while(kh && i<sizeof s /sizeof s[0]);
			if (l&8)s[i++]='-';								//��ӷ��ţ�ע���λ��ǰ��
			fl=0;	
			goto PRT;
		}
		case 'B' :					/* Binary */
			r = 2; break;
		case 'O' :					/* Octal */
			r = 8; break;
		case 'D' :					/* Signed decimal */
		case 'U' :					/* Unsigned decimal */
			r = 10; break;
		case 'X' :					/* Hexdecimal */
			r = 16; break;
		default:{					/* Unknown type (pass-through) */
				myputc(c);								
				cc=1;
				continue;
			}
		}

		/* Get an argument and put it in numeral */
/*ȡ����  ��%ld�ͣ�		����longȡ����			û��l����d��intȡ����						û��lҲû��d���Ȱ�unsigned intȡ������������	*/
		v =(f&4)?(unsigned long)va_arg(arp, long):((d=='D')?(unsigned long)(long)va_arg(arp, int):(unsigned long)va_arg(arp, unsigned int));
		if (d == 'D' && (v & 0x80000000)) {					//��%d���ҷ���λΪ1��������	//ֻ��int��������֮��
			v = 0 - v;										//����Ϊ��������
			f |= 8;											//f���ű��λ��1
		}
		i = 0;
		do {												//���ֽ������ַ�
			d=(char)(v%r);									//������rȡ�࣬��ȡ��λ������Ϊ�ַ�����
			v/=r;											//�ݽ�
			if(d>9)d+=(c=='x')?0x27:0x07;					//�ж�������10���ƶ���16����ʱ��d���ȼ�һ�������ת��'A'(��дX)��'a'(СдX)
			s[i++]=d+'0';									//����Ϊ�ַ�������ע���λ��ǰ��
		} while (v && i<sizeof s /sizeof s[0]);				//��i<sizeof s /sizeof s[0]����ֹ��0����������
		if (f & 8) s[i++] = '-';							//��ӷ��ţ�ע���λ��ǰ��
PRT:		
		j=i;
		d=(f&1)?'0':' ';									//�ж�0��仹�������
		while (!(f&2)&&j++<w)
		{
			myputc(d);									
		}
		do 
		{
			myputc(s[--i]);									
		}while(i);

		while (j++ < w) 
		{
			myputc(d);										
		}
	}
}








