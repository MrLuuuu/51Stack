#include "keyboard.h"

char Keyboard_Down(void)
{
	char KeyValue=16;
	KEY=0x0f;
	if(KEY!=0x0f)//��ȡ�����Ƿ���
	{
		delay_ms(10);//��ʱ10ms��������
		if(KEY!=0x0f)//�ٴμ������Ƿ���
		{	
			//������
			KEY=0X0F;
			switch(KEY)
			{
				case(0X07):	KeyValue=0;break;
				case(0X0b):	KeyValue=1;break;
				case(0X0d): KeyValue=2;break;
				case(0X0e):	KeyValue=3;break;
			}
			//������
			KEY=0XF0;
			switch(KEY)
			{
				case(0X70):	KeyValue=KeyValue;break;
				case(0Xb0):	KeyValue=KeyValue+4;break;
				case(0Xd0): KeyValue=KeyValue+8;break;
				case(0Xe0):	KeyValue=KeyValue+12;break;
			}
		}
	}
	return KeyValue;
}