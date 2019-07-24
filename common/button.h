#ifndef BUTTON_H_
#define BUTTON_H_
#include "reg52.h"
#include "delay.h"

sbit Button_1=P3^1;//K1
sbit Button_2=P3^0;//K2
sbit Button_3=P3^2;//K3
sbit Button_4=P3^3;//K4

extern char Button_Down();

#endif
