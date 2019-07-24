#ifndef INTERRUPT_H_
#define INTERRUPT_H_
#include"reg52.h"
#include"main.h"
//外部中断触发口为P3^2(IT0)\P3^3(IT1)

extern void InterruptInit(unsigned char port);//中断初始化函数，0中断0，1中断1
#endif