/*
* Keyboard.cpp
*
* Created: 2014-01-28 14:34:58
*  Author: gauee
*/

#include "Keyboard.h"

/*
PC7 - w1
PC6 - w2
PC5 - w3
PC4 - w4
PC3 - k1
PC2 - k2
PC1 - k3
PC0 - k4
*/



KeyboardController::KeyboardController(){}

KeyboardController::~KeyboardController(){}

void KeyboardController::setKeyValue(int val){
	readKey = val;
}

KeyItem KeyboardController::readValueFromKeyboard(){

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
		return KeyItem();
	}else{
		readKey = KeyboardValues[row-1][col-1];
	}
	
	
	//liczby przechowywane w int
	
	if(readKey != 4){
		initOperatorId();
	}
	
	if(readKey == 4){					//operator +,-,*,/
		return KeyOperator(oprtrs[getNextOperator()]);
		}else if(readKey % 4 ==0){			//memory operations
		return KeyMemo(readKey/4);
		}else if(readKey == 13){			//Cleaning calculations
		return KeyClean();
		}else if(readKey == 15){			//Finish calculate
		return KeyResult();
		}else{								//Numbers left
		
		int val = 0;
		if(readKey < 4){
			val+=readKey;
		}else if(readKey < 8){
			val +=(readKey-1);
		}else if(readKey < 12){
			val +=(readKey-2);
		}
		
		return KeyNumber(val);
	}
}

int KeyboardController::getNextOperator(){
	return (++operatorId)%MAX_OPERATORS;
}

void KeyboardController::initOperatorId(){
	operatorId = MAX_OPERATORS-1;
}

void KeyboardController::initPortC(){
	
}

void KeyboardController::initKeyboard(){
	
}

