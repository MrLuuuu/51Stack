#include "delay.h"
#include "iic.h"




/*************IIC起始信号***********************
*
**备注           : 起始之后SDA和SCL都为0
*/
void IICStart()
{
	SDA=1;
	delay_10us();
	SCL=1;
	delay_10us();//建立时间是SDA保持时间>4.7us
	SDA=0;
	delay_10us();//保持时间是>4us
	SCL=0;			
	delay_10us();
}

/*************IIC结束信号***********************
*
*备注           : 结束之后保持SDA和SCL都为1；表示总线空闲
*/
void IICEnd()
{
	SDA=0;
	delay_10us();
	SCL=1;
	delay_10us();//建立时间大于4.7us
	SDA=1;
	delay_10us();
}

/*******************************************************************************
* 函数名         : IICSendByte(unsigned char dat)
* 函数功能		 : 通过I2C发送一个字节。在SCL时钟信号高电平期间，保持发送信号SDA保持稳定
* 输入           : num
* 输出         	 : 0或1。发送成功返回1，发送失败返回0
* 备注           : 发送完一个字节SCL=0,SDA=1
*******************************************************************************/

unsigned char IICSendByte(unsigned char dat)
{
	unsigned char a=0,b=0;//最大255，一个机器周期为1us，最大延时255us。		
	for(a=0;a<8;a++)//要发送8位，从最高位开始
	{
		SDA=dat>>7;	 //起始信号之后SCL=0，所以可以直接改变SDA信号
		dat=dat<<1;
		delay_10us();
		SCL=1;
		delay_10us();//建立时间>4.7us
		SCL=0;
		delay_10us();//时间大于4us		
	}
	SDA=1;
	delay_10us();
	SCL=1;
	while(SDA)//等待应答，也就是等待从设备把SDA拉低
	{
		b++;
		if(b>200)	 //如果超过2000us没有应答发送失败，或者为非应答，表示接收结束
		{
			SCL=0;
			delay_10us();
			return 0;
		}
	}
	SCL=0;
	delay_10us();
 	return 1;		
}

/*******************************************************************************
* 函数名         : IICReadByte()
* 函数功能		   : 使用I2c读取一个字节
* 输入           : 无
* 输出         	 : dat
* 备注           : 接收完一个字节SCL=0,SDA=1.
*******************************************************************************/
unsigned char IICReadByte()
{
	unsigned char a=0,dat=0;
	SDA=1;			//起始和发送一个字节之后SCL都是0
	delay_10us();
	for(a=0;a<8;a++)//接收8个字节
	{
		SCL=1;
		delay_10us();
		dat<<=1;
		dat|=SDA;
		delay_10us();
		SCL=0;
		delay_10us();
	}
	return dat;		
}