#ifndef MAIN_H_
#define MAIN_H_

/*****include path**************************/
#include "reg52.h"
#include<intrins.h>//包含位左右移的函数的头文件
#include "uart.h"//uart串口
#include "delay.h"//延时函数
#include "nixietube.h"//数码管
#include "button.h"//独立按键
#include "keyboard.h"//键盘
#include "interrupt.h"//外部中断
#include "timer.h"//定时器中断
#include "string.h"
#include "iic.h"
#include "at24c02.h"
#include<stdio.h>
/*****define path***************************/


/*****typedef path**************************/
typedef unsigned char u8;//一个字节，不能表示负数
typedef unsigned int u16;//在该编译器中int型占2个字节

/*****extern path**************************/
extern void IT0_Process();
extern void IT1_Process();
extern void Timer_0_Process();
extern void Timer_1_Process();
#endif