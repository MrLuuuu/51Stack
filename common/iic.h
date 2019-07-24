#ifndef __IIC_H_
#define __IIC_H_
#include "reg52.h"

sbit SCL=P2^1;//IIC时钟
sbit SDA=P2^0;//IIC数据

extern unsigned char IICReadByte();//读取数据
extern unsigned char IICSendByte(unsigned char dat);//发送数据
extern void IICEnd();//终止信号
extern void IICStart();//开始信号













#endif