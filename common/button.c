#include "button.h"

char Button_Down()
{
	if(Button_1==0)
	{
		delay_ms(10);//消抖
		if(Button_1==0)
			return 1;
	}

	if(Button_2==0)
	{
		delay_ms(10);//消抖
		if(Button_2==0)
			return 2;
	}

	if(Button_3==0)
	{
		delay_ms(10);//消抖
		if(Button_3==0)
			return 3;
	}

	if(Button_4==0)
	{
		delay_ms(10);//消抖
		if(Button_4==0)
			return 4;
	}

	return 0;
}