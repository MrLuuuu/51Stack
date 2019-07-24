#include "reg52.h"
#include "main.h"
#ifndef UART_H_
#define UART_H_

sbit RX=P3^0;
sbit TX=P3^1;
#define SYSTEM_OSC 12000000	//Ĭ�Ͼ���12M
//����ı�ʱ�޸��б�
//���㹫ʽ��TH1=TL1=256-SYSTEM_OSC/12/16/Baudrate
#define BAUDRATE_1200 0xCC
#define BAUDRATE_2400 0xE6
#define BAUDRATE_4800 0xF3//9600���ϲ�����,������
//#define BAUDRATE_9600 0xFA
//#define BAUDRATE_14400 0xFC
//#define BAUDRATE_19200 0xFD
//#define BAUDRATE_38400 0xFE

extern void UartOpen(unsigned int baudrate);//���벨����
extern void UartWrite(unsigned char *p,unsigned int length);//����д
//extern char UartRead(unsigned char *p,unsigned int length);//���ڶ�
//extern unsigned char readbuffer[20];

#endif