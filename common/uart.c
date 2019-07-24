#include "reg52.h"
#include "uart.h"


unsigned char data_count=0;
/*******************
*SCON:SM0 SM1 SM2 REN TB8 RB8 TI RI
*SM0 SM1:00 ��λ�Ĵ���;01 10λ�첽�ɱ䲨����;10 11λ�첽�̶�������;11 11λ�ɱ䲨����
*SM2:���ͨ�ſ���λ,����ģʽ2��3��ʹ;ģʽ1��Ϊ0
*REN:�����н���,��Ϊ1
*TB8 RB8:ģʽ2��3ʹ��,��Ϊ0
*TI:���������1�����ж�,���������0
*RI:���������1�����ж�,���������0
****************/



void UartOpen(unsigned int baudrate)
{
	SCON=0x50;//���ù�����ʽΪ1
	PCON|=0x80;//�����ʱ���λ,��ʽ1��2��3ʱ,���λ�Ĵ�����1ʱ�����ʱ���
	TMOD|=0x20;//ʹ�ö�ʱ��1��ʱ,8λ�Զ���װ
	switch(baudrate){
	case 1200:TH1=TL1=BAUDRATE_1200;break;
	case 2400:TH1=TL1=BAUDRATE_2400;break;
	case 4800:TH1=TL1=BAUDRATE_4800;break;
//	case 9600:TH1=TL1=BAUDRATE_9600;break;
//	case 14400:TH1=TL1=BAUDRATE_14400;break;
//	case 19200:TH1=TL1=BAUDRATE_19200;break;
//	case 38400:TH1=TL1=BAUDRATE_38400;break;
	default:TH1=TL1=BAUDRATE_4800;break;
	}
//	ES=1;//�򿪽����ж�
//	EA=1;//�����ж�
	TR1=1;//�򿪶�ʱ��
}

//void Uart() interrupt 4
//{
//	if(RI)
//		if((SBUF!='\n')||(SBUF!='\0'))
//			readbuffer[data_count++]=SBUF;//��SBUF������������ȡ����
//	RI=0;//��ս����ж�	
//}

//char UartRead(unsigned char*p,unsigned int length)
//{
//    static unsigned char flag=0;
////	char *buffer=p;
////	*buffer=SBUF;
////	loop:
////	RI=0;//��ս����ж�
////	if(flag<length)
////	{
////		p[flag]=*buffer;
////		flag++;
////		buffer++;
////		if( (*buffer=='\n')||(*buffer=='\0')||(*buffer==0) )
////			return 0;
////		goto loop;
////	}
//	char ch=SBUF;
//	RI=0;//��Ϊ����һ��
//	strcat(p,&ch);
//		flag++;
//		Nixietube_Display(flag+'0',0);
//		if(flag==length)
//		{
//			flag=0;
//			return 0;
//		}
//	
//	return 0;
//}

void UartWrite(unsigned char *p,unsigned int length)
{
	int i=0;
//	ES=0;
//	EA=0;//�ص��жϣ���������жϴ�����
	for(i=0;i<length-1;i++)
	{
		if((p[i]=='\n')||(p[i]=='\0')||(p[i]==0))
			break;
		SBUF=p[i];
		while(!TI);
		TI=0;
	}
	SBUF='\n';
	while(!TI);
	TI=0;
//	ES=1;//�򿪽����ж�
//	EA=1;//�����ж�
} 