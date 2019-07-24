#include"reg52.h"
#include"nixietube.h"

unsigned char code font[17]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};//显示0~F的值

void Nixietube_Display(unsigned char ch,unsigned char position)
{
	Decoder_H=position%2;//高位

	switch(position){
	case 2:;
	case 3:;
	case 6:;
	case 7:Decoder_M=1;break;
	default: Decoder_M=0;
	}//中位

	if(position>=4){
		Decoder_L=1;
	}else{
		Decoder_L=0;
	}//低位
	( (ch>='0')&&(ch<='9')) ? (nixietube=font[ch-'0']) : ( ((ch>='a')&&(ch<='f')) ? (nixietube=font[ch-87]) : (nixietube=font[ch-55]) );
	delay_ms(1);
	nixietube=0x00;//消影
}