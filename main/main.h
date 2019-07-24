#ifndef MAIN_H_
#define MAIN_H_

/*****include path**************************/
#include "reg52.h"
#include<intrins.h>//����λ�����Ƶĺ�����ͷ�ļ�
#include "uart.h"//uart����
#include "delay.h"//��ʱ����
#include "nixietube.h"//�����
#include "button.h"//��������
#include "keyboard.h"//����
#include "interrupt.h"//�ⲿ�ж�
#include "timer.h"//��ʱ���ж�
#include "string.h"
#include "iic.h"
#include "at24c02.h"
#include<stdio.h>
/*****define path***************************/


/*****typedef path**************************/
typedef unsigned char u8;//һ���ֽڣ����ܱ�ʾ����
typedef unsigned int u16;//�ڸñ�������int��ռ2���ֽ�

/*****extern path**************************/
extern void IT0_Process();
extern void IT1_Process();
extern void Timer_0_Process();
extern void Timer_1_Process();
#endif