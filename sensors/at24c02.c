#include "iic.h"
#include "at24c02.h"

/*******************************************************************************
* 函数名         : void At24c02Write(unsigned char addr,unsigned char dat)
* 函数功能		   : 往24c02的一个地址写入一个数据
* 输入           : 无
* 输出         	 : 无
*******************************************************************************/

void At24c02Write(unsigned char addr,unsigned char dat)
{
	IICStart();
	IICSendByte(0xa0);//发送写器件地址
	IICSendByte(addr);//发送要写入内存地址
	IICSendByte(dat);	//发送数据
	IICEnd();
}
/*******************************************************************************
* 函数名         : unsigned char At24c02Read(unsigned char addr)
* 函数功能		   : 读取24c02的一个地址的一个数据
* 输入           : 无
* 输出         	 : 无
*******************************************************************************/

unsigned char At24c02Read(unsigned char addr)
{
	unsigned char num;
	IICStart();
	IICSendByte(0xa0); //发送写器件地址
	IICSendByte(addr); //发送要读取的地址
	IICStart();
	IICSendByte(0xa1); //发送读器件地址
	num=IICReadByte(); //读取数据
	IICEnd();
	return num;	
}