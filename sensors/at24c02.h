#ifndef __AT24C02_H_
#define	__AT24C02_H_

unsigned char At24c02Read(unsigned char addr);//EEPROM读取相应地址数据
void At24c02Write(unsigned char addr,unsigned char dat);//EEPROM向地址写数据
														  

#endif