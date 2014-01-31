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
	};

LCDController::~LCDController(){};

void LCDController::cleanDisplay(){
	LCD_Clear();
	for(int i=0;i<MAX_CALC_OPER_SIZE;++i){
		calcOperStr[i]=0;
	}
	curIdx =0;
};

void LCDController::loadCalcResult(CalcResult* cr){
	for(int i=0;i<cr->size;++i){
		calcOperStr[curIdx++] = cr->tableResult[i];
	}
	displayCalcOperation();
}

void LCDController::writeCalcResult(CalcResult* cr){
	cleanDisplay();
	calcOperStr[curIdx++] = '=';
	loadCalcResult(cr);
}

void LCDController::displayCalcOperation(){
	LCD_Text(calcOperStr);
}