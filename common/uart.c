#include "reg52.h"
#include "uart.h"


unsigned char data_count=0;
/*******************
*SCON:SM0 SM1 SM2 REN TB8 RB8 TI RI
*SM0 SM1:00 移位寄存器;01 10位异步可变波特率;10 11位异步固定波特率;11 11位可变波特率
*SM2:多机通信控制位,仅在模式2、3中使;模式1设为0
*REN:允许串行接收,设为1
*TB8 RB8:模式2、3使用,设为0
*TI:发送完成置1触发中断,需用软件清0
*RI:接收完成置1触发中断,需用软件清0
****************/



void UartOpen(unsigned int baudrate)
{
	SCON=0x50;//设置工作方式为1
	PCON|=0x80;//波特率倍增位,方式1、2、3时,最高位寄存器置1时波特率倍增
	TMOD|=0x20;//使用定时器1定时,8位自动重装
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
//	ES=1;//打开接收中断
//	EA=1;//打开总中断
	TR1=1;//打开定时器
}

//void Uart() interrupt 4
//{
//	if(RI)
//		if((SBUF!='\n')||(SBUF!='\0'))
//			readbuffer[data_count++]=SBUF;//将SBUF缓存区内容提取出来
//	RI=0;//清空接收中断	
//}

//char UartRead(unsigned char*p,unsigned int length)
//{
//    static unsigned char flag=0;
////	char *buffer=p;
////	*buffer=SBUF;
////	loop:
////	RI=0;//清空接收中断
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
//	RI=0;//人为开关一次
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
//	EA=0;//关掉中断，避免进入中断处理中
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
//	ES=1;//打开接收中断
//	EA=1;//打开总中断
} 