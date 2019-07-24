#include "delay.h"

//note:_nop_() 延时一个机器周期，一个机械周期为12个时钟周期，一个时钟周期为晶振频率的导数

//void delay_ms(unsigned int n)//11.0592MHz晶振 
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

void delay_ms(unsigned int n)//12MHz晶振,毫秒延时
{
	unsigned int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<123;j++);
}

void delay_s(unsigned int n)//12MHz晶振,秒延时
{
	unsigned int i=0,j=0;
    for(i=0;i<n*10;i++)
        for(j=0;j<21738;j++);
}
