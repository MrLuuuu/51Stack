#ifndef __IIC_H_
#define __IIC_H_
#include "reg52.h"

sbit SCL=P2^1;//IICʱ��
sbit SDA=P2^0;//IIC����

extern unsigned char IICReadByte();//��ȡ����
extern unsigned char IICSendByte(unsigned char dat);//��������
extern void IICEnd();//��ֹ�ź�
extern void IICStart();//��ʼ�ź�













#endif