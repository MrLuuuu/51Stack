#include "delay.h"

//note:_nop_() ��ʱһ���������ڣ�һ����е����Ϊ12��ʱ�����ڣ�һ��ʱ������Ϊ����Ƶ�ʵĵ���

//void delay_ms(unsigned int n)//11.0592MHz���� 
//{ 
//	unsigned int i,j; 
//	for(i=n;i>0;i--) 
//		for(j=114;j>0;j--); 
//}
void delay_10us()
{
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
}

void delay_ms(unsigned int n)//12MHz����,������ʱ
{
	unsigned int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<123;j++);
}

void delay_s(unsigned int n)//12MHz����,����ʱ
{
	unsigned int i=0,j=0;
    for(i=0;i<n*10;i++)
        for(j=0;j<21738;j++);
}
