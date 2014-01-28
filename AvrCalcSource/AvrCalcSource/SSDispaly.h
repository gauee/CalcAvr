/*
 * SSDispaly.h
 *
 * Created: 2014-01-28 14:12:24
 *  Author: gauee
 */ 
#ifndef SSDISPLAY_H_
#define SSDISPLAY_H_

#include <avr/io.h>

#define MAX_COL 4

uint8_t COLS[MAX_COL] = {
	0b11111110,
	0b11111101,
	0b11111011,
	0b11110111
};

uint8_t numberAt4Cols[MAX_COL] = {0,0,0,0};

uint8_t Digits[10] = {
	0b11000000,		//0
	0b11111001,		//1
	0b10100100,		//2
	0b10110000,		//3
	0b10011001,		//4
	0b10010010,		//5
	0b10000010,		//6
	0b11111000,		//7
	0b10000000,		//8
	0b10010000
};

int cur_idx=0;

void setNumberToDisplay(int val);

void showNextDigit(void);

void initSSDisplay();

void initPortA();
void initPortB();

#endif /* SSDISPLAY_H_ */