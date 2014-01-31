/*
* Keyboard.h
*
* Created: 2014-01-28 14:34:46
*  Author: gauee
*/
#ifndef __KEYBOARD__H__
#define __KEYBOARD__H__

#include <avr/io.h>
#include "KeyItems.h"

//Keyboard uses PORTC

#define MAX_OPERATORS 4

class KeyboardController{

	public:
	KeyboardController();
	~KeyboardController();

	void initKeyboard();
	KeyItem readValueFromKeyboard(void);

	int getNextOperator();
	void initOperatorId();

	void setKeyValue(int val);
	
	private:
	//Variables
	uint8_t KeyboardValues[4][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
	uint8_t zero[16]={0,0,0,0,0,0,0,1,0,0,0,2,0,3,4,0};
	char oprtrs[MAX_OPERATORS] = {'+','-','*','/'};
	int operatorId = 0;
	int readKey;
	//Methods
	void initPortC();
};

#endif /* __KEYBOARD__H__ */