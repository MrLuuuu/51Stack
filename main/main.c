/******************************************
* author:luyouqi
* version:18.1
* function:for 89C51/52
*
*/
#include "main.h"

void IT0_Process()//P3^2口下降沿触发中断处理函数
{
//Add your code here if you have Inited IT0
//InterruptInit(unsigned char port);
}

void IT1_Process()//P3^3口下降沿触发中断处理函数
{
//Add your code here if you have Inited IT1
//InterruptInit(unsigned char port);
}

void Timer_0_Process()//定时器0到达预定时间后的动作
{
//Add your code here if you have Inited Iimer0
//TimerInit(unsigned char port,unsigned int ms);
}

void Timer_1_Process()//定时器1到达预定时间后的动作
{
//Add your code here if you have Inited Iimer1
//TimerInit(unsigned char port,unsigned int ms);
}

void main()
{	
	while(1)
	{
	}
}