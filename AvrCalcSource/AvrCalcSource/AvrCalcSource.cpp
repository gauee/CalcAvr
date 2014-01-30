/*
* AvrCalcSource.cpp
*
* Created: 2014-01-28 14:08:24
*  Author: gauee
*/

#include "Keyboard.h"
#include "AvrCalcSource.h"
#include "calcOperation.h"
#include "HD44780.h"

const int size_table = 128;
char calc[size_table];
int curCalcIdx =-1;
bool lastIsOperator = false;
int main(void)
{
	initPortA();
	LCD_Initalize();
	_delay_ms(100);
	LCD_Text("Damian123");
	
	//KeyboardController keyboardCntlr = KeyboardController();
	//
	////const int COMMANDS_NUM=10;
	////int commands [COMMANDS_NUM] = {1, 2, 3, 4, 1, 2, 4, 4, 1, 15 };
	////for(int i=0;i<COMMANDS_NUM;++i){
		////keyboardCntlr.setKeyValue(commands[i]);
		////readPressedKey(keyboardCntlr);
	////}
	//
	//while(1)
	//{
		//keyboardCntlr.readValueFromKeyboard();
		////TODO:: Please write your application code
	//}
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
	
	if(item.id == ID_NUMBER){
		calc[++curCalcIdx] = '0' + item.getVal();
		lastIsOperator = false;
		return;
	}
	
	if(item.getId() == ID_CLEAN){
		
		getResult().cleanCalcOperation();
		for (int i = 0; i < curCalcIdx + 1; i++ )
		{
			calc[i] = 0;
		}
		
	}
	
	if (item.getId() == ID_MEMO)
	{
		if (item.getVal() == MEMO_WRITE){
			getResult().addToMemo();
		}
		if (item.getVal() == MEMO_READ)
		{
			getResult().readMemo();
		}
		if (item.getVal() == MEMO_ERASE)
		{
			getResult().eraseMemo();
		}
	}
	
	
	if(item.getId() == ID_RESULT){
		// to jest efekt kiedy zczytamy "="
		for(int i = 0; i < size_table;i++){
			calc[i] = 0;
		}
		
		CalcResult rslt = getResult();
		calc[0] = '=';
		for(int i = 0; i < rslt.size; i++){
			
			calc[i + 1] = rslt.tableResult[i];
			
		}
	}
}