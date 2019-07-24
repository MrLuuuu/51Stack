#ifndef DELAY_H_
#define DELAY_H_
//This produces delay by software, and it's not very accurate

#include<intrins.h>
/*****extern path**************************/
extern void delay_10us();
extern void delay_ms(unsigned int n);
extern void delay_s(unsigned int n);

#endif