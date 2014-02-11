/*
* LCDCntrlr.cpp
*
* Created: 2014-01-31 13:28:50
*  Author: gauee
*/

#include "LCD.h"
#include "HD44780.h"

LCDController::LCDController(){
	curIdx =0;
	lastWasOperator = false;
	};

LCDController::~LCDController(){};

void LCDController::initLcd(){
	LCD_Initalize();
	LCD_Text("Init calc");
}

void LCDController::cleanDisplay(){
	LCD_Clear();
	for(int i=0;i<MAX_CALC_OPER_SIZE;++i){
		calcOperStr[i]=0;
	}
	curIdx =0;
};

void LCDController::loadCalcResult(CalcResult* cr){
	if(lastWasOperator){
			++curIdx;
	}

	for(int i=0;i<cr->size;++i){
		calcOperStr[curIdx++] = cr->tableResult[i];
	}
	displayCalcOperation();
}

void LCDController::writeCalcResult(CalcResult* cr){
	cleanDisplay();
	calcOperStr[curIdx++] = '=';
	lastWasOperator=false;
	loadCalcResult(cr);
}

void LCDController::displayCalcOperation(){
	LCD_Clear();
	LCD_Text(calcOperStr);
}

void LCDController::addNumber(int num){
	if(lastWasOperator){
		++curIdx;
	}
	calcOperStr[curIdx++]=('0'+num);
	lastWasOperator = false;
	//display(calcOperStr[curIdx-1]);
	displayCalcOperation();
}

void LCDController::addOperator(char opt){
	calcOperStr[curIdx]=opt;
	lastWasOperator=true;
	//displayOper(calcOperStr[curIdx]);
	displayCalcOperation();
}

void LCDController::display(char c){
	char txt[1] = {c};
	LCD_Text(txt);
}

void LCDController::displayOper(char c){
	LCD_Back();
	display(c);
}