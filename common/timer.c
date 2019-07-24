#include"reg52.h"
#include "main.h"
#define SYSTEM_OSC 12000000 //设置晶振为12M
unsigned int timer0=0;//定时毫秒数
unsigned int timer1=0;//定时毫秒数

void THTLSet(unsigned char port)
{
	unsigned char TH=0x00;
	unsigned char TL=0x00;
	unsigned int T=0x0000;
	T=65536-(SYSTEM_OSC/12/1000);//1ms的机器周期
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

//TMOD低四位设置T0，高四位设置T1，从高到低分别为Gate C/T M1 M0 Gate C/T M1 M0
//Gate:0,将TR0或TR1置为1即可开启定时计数;1,TR0或TR1置1且外部中断引脚也为高电平开启定时计数
//C/T:0,定时；1,计数
//M1M0:00,13位定时器;01,16位定时器;10,8位自动重装定时器;11,T0分为2个8位定时计数器
void TMODSet(unsigned char port)
{
	if(port==0)
	{
		TMOD|=0x01;//16位定时器
	}
	if(port==1)
	{
		TMOD|=0x10;//16位定时器
	}
}

/****
*function:定时器初始化
*input: unsigned char port 定时器0或1;unsigned int ms 定时时间 毫秒为单位
*output:none
**/
void TimerInit(unsigned char port,unsigned int ms)
{
	 TMODSet(port);
	 THTLSet(port);
	 if(port==0)
	 {
	 	ET0=1;//打开定时器中断,外部中断为EX
		EA=1;//打开总中断
		TR0=1;//打开定时器
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
	flag0++;//每毫秒++一次
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
	flag1++;//每毫秒++一次
	if(flag1==timer1)
	{
	 flag1=0;
	 Timer_1_Process();
	}	
}