/*
 * Keyboard.h
 *
 * Created: 2014-01-28 14:34:46
 *  Author: gauee
 */ 
#ifndef KEYBOARD_H_
#define KEYBOARD_H_

#include <avr/io.h>

void readValueFromKeyboard(void);

uint8_t KeyboardValues[4][4] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};

uint8_t zero[16]={0,0,0,0,0,0,0,1,0,0,0,2,0,3,4,0};

int readKey;


#endif /* KEYBOARD_H_ */