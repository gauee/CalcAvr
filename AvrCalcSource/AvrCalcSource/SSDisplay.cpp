/*
 * SSDisplay.cpp
 *
 * Created: 2014-01-28 14:12:38
 *  Author: gauee
 */ 
#include "SSDispaly.h"

void initSSDisplay(){
	initPortA();
	initPortB();
}

void initPortA(){
	DDRA = 0xFF;
}
void initPortB(){
	DDRB = 0xFF;
}

void setNumberToDisplay(int val)
{
	val%=10000;
	numberAt4Cols[0] = val/1000;
	numberAt4Cols[1] = (val%1000)/100;
	numberAt4Cols[2] = (val%100)/10;
	numberAt4Cols[3] = val%10;
}

void showNextDigit(void){
	PORTA = Digits[numberAt4Cols[cur_idx]];
	PORTB = COLS[cur_idx];
	//cur_idx++;
	(++cur_idx)%=MAX_COL;
}