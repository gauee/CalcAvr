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
#include "TaskScheduler.h"


const int size_table = 128;
char calc[size_table];
int curCalcIdx =-1;
bool lastIsOperator = false;
int ile = 0;

KeyboardController keyboardCntlr;
MemoController memoCntlr;
CalcOperation calcOperationCntlr;
LCDController lcdCntrlr;

bool isCountResult = false;

int main(void)
{	

	initAvrCalc();
	//
	const int COMMANDS_NUM=7;
	////21*3+40*5=  //=263
	//int commands [COMMANDS_NUM] = {/*21*/2,1,/*'*'*/4,4,4,/*3*/3,/*'+'*/4,/*40*/5,14,/*'*'*/4,4,4,/*5*/6,/*'='*/15};
	//const int COMMANDS_NUM=8;
	////21*3=  //=63
	//int commands [COMMANDS_NUM] = {/*21*/2,1,/*'*'*/4,4,4,4,/*3*/3,/*'='*/15};
	//const int COMMANDS_NUM=12;
	//21*3=  //=63
	//int commands [COMMANDS_NUM] = {/*999999*/11,11,11,11,11,11,/*'+'*/4,/*1*/1,/*'='*/15};
	//int commands [COMMANDS_NUM] = {/*999999*/3,/*'+'*/4,4,4,4,/*1*/2,/*'='*/15};
	//for(int i=0;i<COMMANDS_NUM;++i){
		//keyboardCntlr.setKeyValue(commands[i]);
		//readPressedKey();
	//}
	//
	//keyboardCntlr.setKeyValue(0);
	
	while(1)
	{
		readPressedKey();
		executeTasks();
		////TODO:: Please write your application code
	}
}

void initAvrCalc(){
	initTaskScheduler();
	memoCntlr = MemoController();
	memoCntlr.initMemoController();
	start_timer();
	
	keyboardCntlr = KeyboardController();
	calcOperationCntlr = CalcOperation();
	lcdCntrlr = LCDController();
	lcdCntrlr.initLcd();
}

void readPressedKey(){
	KeyItem item = keyboardCntlr.readValueFromKeyboard();
	appendKeyItem(item);
}

void appendKeyItem(KeyItem item){
	switch(item.getId()){
		case ID_OPERATOR:
		ile = 0;
			if(isCountResult){
				lcdCntrlr.cleanDisplay();
				lcdCntrlr.loadCalcResult(calcOperationCntlr.getResult());
				appendOperator(item);
				isCountResult = false;
				
				return;
			}
			appendOperator(item);
			return;
		case ID_NUMBER:
			if(!isCountResult && ile < 4){
				appendNumber(item);
				ile++;
			}
			return;
		case ID_CLEAN:
			calcOperationCntlr.cleanCalcOperation();
			lcdCntrlr.cleanDisplay();
			isCountResult = false;
			ile = 0;
			return;
		case ID_MEMO:
			handleMemo(item);
			ile = 0;
			return;
		case ID_RESULT:
			lcdCntrlr.writeCalcResult(calcOperationCntlr.getResult());
			isCountResult = true;
			ile = 0;
			return;
		case ID_NO_INPUT:
		default:
			return;
	}

}

void appendOperator(KeyItem optr){
	lcdCntrlr.addOperator(optr.getVal());
	calcOperationCntlr.addOperator(optr.getVal());
}

void appendNumber(KeyItem number){
	lcdCntrlr.addNumber(number.getVal());
	calcOperationCntlr.addNumber(number.getVal());
}

void handleMemo(KeyItem memo){
	if (MemoController::isMemoWrite(&memo)){
		memoCntlr.addToMemo(calcOperationCntlr.getResult());
	}
	if (MemoController::isMemoRead(&memo)){
		CalcResult* rslt = memoCntlr.readFromMemo();
		calcOperationCntlr.loadCalcResult(rslt);
		lcdCntrlr.loadCalcResult(rslt);
	}
	if (MemoController::isMemoErase(&memo)){
		memoCntlr.eraseFromMemo();
	}
}
