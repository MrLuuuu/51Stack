#ifndef NIXIETUBE_H_
#define NIXIETUBE_H_
#include "delay.h"
sbit Decoder_H=P2^2;//38��������λIO��
sbit Decoder_M=P2^3;//38��������λIO��
sbit Decoder_L=P2^4;//38��������λIO��

#define nixietube P0//����ܽ���MCUλ��

extern void Nixietube_Display(unsigned char ch,unsigned char position);//��ʾ����,��һ��������Ҫ��ʾ���ַ����ڶ�����������ʾλ��

#endif