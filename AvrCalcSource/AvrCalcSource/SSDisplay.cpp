/*
 * SSDisplay.cpp
 *
 * Created: 2014-01-28 14:12:38
 *  Author: gauee
 */ 
#include "SSDispaly.h"

void SSDisplay::initSSDisplay(){
	initPortB();
}

void SSDisplay::initPortB(){
	DDRA = 0xFF;
}

void SSDisplay::setNumberToDisplay(int val)
{
	val%=10000;
	numberAt4Cols[0] = val/1000;
	numberAt4Cols[1] = (val%1000)/100;
	numberAt4Cols[2] = (val%100)/10;
	numberAt4Cols[3] = val%10;
}

void SSDisplay::showNextDigit(void){
	PORTA = Digits[numberAt4Cols[cur_idx]];
	PORTB = COLS[cur_idx];
	//cur_idx++;
	(++cur_idx)%=MAX_COL;
}