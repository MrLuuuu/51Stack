#include"interrupt.h"

void Interrupt_0_Init()
{
	EA=1;//�����ж�
	EX0=1;//���ⲿ�ж�0
	IT0=1;//������ʽ����Ϊ�½���
}

void Interrupt_0_Process() interrupt 0
{
	IT0_Process();//��main.c�ж���
}

void Interrupt_1_Init()
{
	EA=1;//�����ж�
	EX1=1;//���ⲿ�ж�1
	IT1=1;//������ʽ����Ϊ�½���
}

void Interrupt_1_Process() interrupt 2
{
	IT1_Process();//��main.c�ж���
}

void InterruptInit(unsigned char port)
{
	if(port==0)
		Interrupt_0_Init();
	if(port==1)
		Interrupt_1_Init();
} 