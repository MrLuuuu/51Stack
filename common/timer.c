#include"reg52.h"
#include "main.h"
#define SYSTEM_OSC 12000000 //���þ���Ϊ12M
unsigned int timer0=0;//��ʱ������
unsigned int timer1=0;//��ʱ������

void THTLSet(unsigned char port)
{
	unsigned char TH=0x00;
	unsigned char TL=0x00;
	unsigned int T=0x0000;
	T=65536-(SYSTEM_OSC/12/1000);//1ms�Ļ�������
	TH=T/256;
	TL=T%256;
	if(port==0)
	{
	 TH0=TH;
	 TL0=TL;
	}
	if(port==1)
	{
	 TH1=TH;
	 TL1=TL;
	}
}

//TMOD����λ����T0������λ����T1���Ӹߵ��ͷֱ�ΪGate C/T M1 M0 Gate C/T M1 M0
//Gate:0,��TR0��TR1��Ϊ1���ɿ�����ʱ����;1,TR0��TR1��1���ⲿ�ж�����ҲΪ�ߵ�ƽ������ʱ����
//C/T:0,��ʱ��1,����
//M1M0:00,13λ��ʱ��;01,16λ��ʱ��;10,8λ�Զ���װ��ʱ��;11,T0��Ϊ2��8λ��ʱ������
void TMODSet(unsigned char port)
{
	if(port==0)
	{
		TMOD|=0x01;//16λ��ʱ��
	}
	if(port==1)
	{
		TMOD|=0x10;//16λ��ʱ��
	}
}

/****
*function:��ʱ����ʼ��
*input: unsigned char port ��ʱ��0��1;unsigned int ms ��ʱʱ�� ����Ϊ��λ
*output:none
**/
void TimerInit(unsigned char port,unsigned int ms)
{
	 TMODSet(port);
	 THTLSet(port);
	 if(port==0)
	 {
	 	ET0=1;//�򿪶�ʱ���ж�,�ⲿ�ж�ΪEX
		EA=1;//�����ж�
		TR0=1;//�򿪶�ʱ��
		timer0=ms;
	 }
	 if(port==1)
	 {
	 	ET1=1;
		EA=1;
		TR1=1;
		timer1=ms;
	 }
}

void Timer_0() interrupt 1
{
	static unsigned int flag0;
    THTLSet(0);
	flag0++;//ÿ����++һ��
	if(flag0==timer0)
	{	
	 flag0=0;
	 Timer_0_Process();	
	}
}

void Timer_1() interrupt 3
{
	static unsigned int flag1;
	THTLSet(1);
	flag1++;//ÿ����++һ��
	if(flag1==timer1)
	{
	 flag1=0;
	 Timer_1_Process();
	}	
}