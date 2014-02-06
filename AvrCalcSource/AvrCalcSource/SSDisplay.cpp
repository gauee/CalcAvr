/*
* SSDisplay.cpp
*
* Created: 2014-01-28 14:12:38
*  Author: gauee
*/
#include "SSDispaly.h"
#include "TaskScheduler.h"

static const int MAX_COL = 4;
static const int DIGITS_SIZE = 10;
static int cur_idx;
static uint8_t numberAt4Cols[MAX_COL];
static uint8_t COLS[MAX_COL] = {
	0b11111110,
	0b11111101,
	0b11111011,
	0b11110111
};
static uint8_t Digits[DIGITS_SIZE] = {
	0b11000000,		//0
	0b11111001,		//1
	0b10100100,		//2
	0b10110000,		//3
	0b10011001,		//4
	0b10010010,		//5
	0b10000010,		//6
	0b11111000,		//7
	0b10000000,		//8
	0b10010000		//9
};

SSDisplay::SSDisplay(){
	powVal=1;
	for(int i=0;i<MAX_COL;++i){
		powVal *=10;
	}
}

SSDisplay::~SSDisplay(){
	
}

void SSDisplay::initSSDisplay(){
	cur_idx = 0;
	initPortB();
	initPortD();
	add_task(showNextDigit,5);
}

void SSDisplay::initPortB(){
	DDRB = 0xFF;
}

void SSDisplay::initPortD(){
	DDRD = 0xFF;
}

void SSDisplay::setNumberToDisplay(int val)
{
	int pow = powVal;
	for(int i=0;i<MAX_COL;++i){
		val%=pow;
		pow /=10;
		numberAt4Cols[i] = val/pow;
	}
}

void SSDisplay::showNextDigit(void){
	PORTB = Digits[numberAt4Cols[cur_idx]];
	PORTD = COLS[cur_idx];
	(++cur_idx)%=MAX_COL;
}