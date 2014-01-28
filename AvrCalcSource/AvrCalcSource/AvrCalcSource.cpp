/*
* AvrCalcSource.cpp
*
* Created: 2014-01-28 14:08:24
*  Author: gauee
*/

#include "Keyboard.h"
#include "AvrCalcSource.h"

char calc[128];
int curCalcIdx =-1;
bool lastIsOperator = false;

int main(void)
{
	KeyboardController keyboardCntlr = KeyboardController();
	
	const int COMMANDS_NUM=10;
	int commands [COMMANDS_NUM] = {1, 2, 3, 4, 1, 2, 4, 4, 1, 15 };
	for(int i=0;i<COMMANDS_NUM;++i){
		keyboardCntlr.setKeyValue(commands[i]);
		readPressedKey(keyboardCntlr);
	}
	
	while(1)
	{
		//TODO:: Please write your application code
	}
}

int readPressedKey(KeyboardController keyboardCntlr){
	KeyItem item = keyboardCntlr.readValueFromKeyboard();
	appendKeyItem(item);
}

void appendKeyItem(KeyItem item){
	if(item.getId() == ID_OPERATOR){
		if(!lastIsOperator){
			++curCalcIdx;
		}
		calc[curCalcIdx] = (char)item.getVal();
		lastIsOperator = true;
		return;
	}
	
	if(item.getId() == ID_NUMBER){
		calc[++curCalcIdx] = (char)item.getVal();
		lastIsOperator = false;
		return;
	}
	
	if(item.getId() == ID_RESULT){
		
	}
}