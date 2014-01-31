/*
* AvrCalcSource.cpp
*
* Created: 2014-01-28 14:08:24
*  Author: gauee
*/

#include "Keyboard.h"
#include "CalcOperation.h"
#include "Memo.h"
#include "LCD.h"
#include "AvrCalcSource.h"


const int size_table = 128;
char calc[size_table];
int curCalcIdx =-1;
bool lastIsOperator = false;

KeyboardController keyboardCntlr;
MemoController memoCntlr;
CalcOperation calcOperationCntlr;
LCDController lcdCntrlr;

int main(void)
{

	initAvrCalc();
	//
	////const int COMMANDS_NUM=10;
	////int commands [COMMANDS_NUM] = {1, 2, 3, 4, 1, 2, 4, 4, 1, 15 };
	//for(int i=0;i<COMMANDS_NUM;++i){
	////keyboardCntlr.setKeyValue(commands[i]);
	////readPressedKey(keyboardCntlr);
	////}
	//
	while(1)
	{
		readPressedKey();
		////TODO:: Please write your application code
	}
}

void initAvrCalc(){
	keyboardCntlr = KeyboardController();
	memoCntlr = MemoController();
	calcOperationCntlr = CalcOperation();
	lcdCntrlr = LCDController();
}

void readPressedKey(){
	KeyItem item = keyboardCntlr.readValueFromKeyboard();
	appendKeyItem(item);
}

void appendKeyItem(KeyItem item){
	if(item.getId() == ID_NO_INPUT){
		return;
	}
	
	if(item.getId() == ID_OPERATOR){
		appendOperator(item);
		
		return;
	}
	
	if(item.id == ID_NUMBER){
		appendNumber(item);
		return;
	}
	
	if(item.getId() == ID_CLEAN){
		
		calcOperationCntlr.cleanCalcOperation();
		lcdCntrlr.cleanDisplay();
		
		//CalcResult cr = calcOperationCntlr.getResult();
		//getResult().cleanCalcOperation();
		//for (int i = 0; i < curCalcIdx + 1; i++ )
		//{
		//calc[i] = 0;
		//}
		
	}
	
	if (item.getId() == ID_MEMO)
	{
		if (MemoController::isMemoWrite(&item)){
			memoCntlr.addToMemo(calcOperationCntlr.getResult());
		}
		if (MemoController::isMemoRead(&item)){
			CalcResult* rslt = memoCntlr.readFromMemo();
			calcOperationCntlr.loadCalcResult(rslt);
			lcdCntrlr.loadCalcResult(rslt);
		}
		if (MemoController::isMemoErase(&item)){
			memoCntlr.eraseFromMemo();
		}
	}
	
	
	if(item.getId() == ID_RESULT){
		// to jest efekt kiedy zczytamy "="
		lcdCntrlr.writeCalcResult(calcOperationCntlr.getResult());
	}
}

void appendOperator(KeyItem optr){
	if(!lastIsOperator){
		++curCalcIdx;
	}
	calc[curCalcIdx] = (char)optr.getVal();
	lastIsOperator = true;
}

void appendNumber(KeyItem number){
	calc[++curCalcIdx] = '0' + number.getVal();
	lastIsOperator = false;
}