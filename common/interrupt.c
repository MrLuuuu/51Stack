#include"interrupt.h"

void Interrupt_0_Init()
{
	EA=1;//打开总中断
	EX0=1;//打开外部中断0
	IT0=1;//触发方式设置为下降沿
}

void Interrupt_0_Process() interrupt 0
{
	IT0_Process();//在main.c中定义
}

void Interrupt_1_Init()
{
	EA=1;//打开总中断
	EX1=1;//打开外部中断1
	IT1=1;//触发方式设置为下降沿
}

void Interrupt_1_Process() interrupt 2
{
	IT1_Process();//在main.c中定义
}

void InterruptInit(unsigned char port)
{
	if(port==0)
		Interrupt_0_Init();
	if(port==1)
		Interrupt_1_Init();
} 