/*
 * Keyboard.cpp
 *
 * Created: 2014-01-28 14:34:58
 *  Author: gauee
 */ 

#include <Keyboard.h>

void readValueFromKeyboard(){
	PORTC = 0;
	DDRC = 0xF0;
	PORTC = 0x0F;
	for(int i=0;i<100;++i){}
	int col= zero[PINC];
	
	PORTC = 0;
	DDRC = 0x0F;
	PORTC = 0xF0;
	for(int i=0;i<100;++i){}
	int row = zero[PINC>>4];
	
	if(row == 0 || col == 0){
		readKey =0;
	}else{
		readKey = KeyboardValues[row-1][col-1];
	}
	
}
