/*
 * HD44780.cpp
 *
 * Created: 2014-01-28 14:27:21
 *  Author: gauee
 */ 
#include "HD44780.h"

#define E PA5
#define RS PA4

void WriteNibble(unsigned char nibbleToWrite)
{
	PORTA |= (1<<E);
	PORTA &= 0xF0;
	PORTA |= (nibbleToWrite & 0x0F);
	PORTA &=~(1<<E);
}

//
void WriteByte(unsigned char dataToWrite)
{
	WriteNibble(dataToWrite >> 4);
	WriteNibble(dataToWrite);
	_delay_us(50);
}


void LCD_Command(unsigned char data)
{
	PORTA &= ~(1<<RS);
	WriteByte(data);
};

void LCD_Text(char *text)
{
	PORTA |= (1<<RS);
	while(*text != 0){
		WriteByte(*text++);
	}
};

void LCD_GoToXY(unsigned char x, unsigned char y)
{
};

void LCD_Clear(void)
{
	LCD_Command(0x01);
	_delay_ms(10);
};

void LCD_Home(void)
{
	LCD_Command(0x02);
	_delay_us(100);
};

void LCD_Initalize(void)
{
	initPortA();
	_delay_ms(20);
	for(int i=0;i<3;++i){
		WriteNibble(0x03);
		_delay_ms(10);
	}
	WriteNibble(0x02);
	_delay_ms(5);
	WriteByte(0x28);
	_delay_ms(5);
	WriteByte(0x08);
	_delay_ms(5);
	WriteByte(0x01);
	_delay_ms(5);
	WriteByte(0x06);
	_delay_ms(5);
	WriteByte(0x0F);
	_delay_ms(5);
	
};

void initPortA(void){
	DDRA = 0xFF;
}
