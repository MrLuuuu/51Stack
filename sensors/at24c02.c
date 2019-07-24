#include "iic.h"
#include "at24c02.h"

/*******************************************************************************
* ������         : void At24c02Write(unsigned char addr,unsigned char dat)
* ��������		   : ��24c02��һ����ַд��һ������
* ����           : ��
* ���         	 : ��
*******************************************************************************/

void At24c02Write(unsigned char addr,unsigned char dat)
{
	IICStart();
	IICSendByte(0xa0);//����д������ַ
	IICSendByte(addr);//����Ҫд���ڴ��ַ
	IICSendByte(dat);	//��������
	IICEnd();
}
/*******************************************************************************
* ������         : unsigned char At24c02Read(unsigned char addr)
* ��������		   : ��ȡ24c02��һ����ַ��һ������
* ����           : ��
* ���         	 : ��
*******************************************************************************/

unsigned char At24c02Read(unsigned char addr)
{
	unsigned char num;
	IICStart();
	IICSendByte(0xa0); //����д������ַ
	IICSendByte(addr); //����Ҫ��ȡ�ĵ�ַ
	IICStart();
	IICSendByte(0xa1); //���Ͷ�������ַ
	num=IICReadByte(); //��ȡ����
	IICEnd();
	return num;	
}