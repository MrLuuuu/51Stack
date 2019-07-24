#ifndef NIXIETUBE_H_
#define NIXIETUBE_H_
#include "delay.h"
sbit Decoder_H=P2^2;//38译码器高位IO口
sbit Decoder_M=P2^3;//38译码器中位IO口
sbit Decoder_L=P2^4;//38译码器低位IO口

#define nixietube P0//数码管接入MCU位置

extern void Nixietube_Display(unsigned char ch,unsigned char position);//显示函数,第一个参数是要显示的字符，第二个参数是显示位置

#endif