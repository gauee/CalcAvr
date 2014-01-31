/*
* Keyboard.h
*
* Created: 2014-01-28 20:34:46
*  Author: gauee
*/
#ifndef __KEYBOARD__ITEMS__H__
#define __KEYBOARD__ITEMS__H__

#include <avr/io.h>

//#define MEMO_WRITE 2
//#define MEMO_READ 3
//#define MEMO_ERASE 4

static const int ID_NO_INPUT = 0;
static const int ID_OPERATOR = 1;
static const int ID_MEMO = 2;
static const int ID_CLEAN = 3;
static const int ID_RESULT = 4;
static const int ID_NUMBER = 5;
//#define ID_NO_INPUT 0
//#define ID_OPERATOR 1
//#define ID_MEMO 2
//#define ID_CLEAN 3
//#define ID_RESULT 4
//#define ID_NUMBER 5

class KeyItem{
	public:
	uint8_t val;
	uint8_t id;
	KeyItem(){
		id = ID_NO_INPUT;
	}
	
	uint8_t getVal(){
		return val;
	}
	uint8_t getId(){
		return id;
	}
	
};

class KeyOperator : public KeyItem{
	public:
	KeyOperator(char a){
		val = a;
		id = ID_OPERATOR;
	}
	
	~KeyOperator(){}
};

class KeyMemo : public KeyItem{
	public:
	
	KeyMemo(int option){
		val = option;
		id=ID_MEMO;
	}
};

class KeyClean : public KeyItem{
	public:
	KeyClean(){
		val=0;
		id=ID_CLEAN;
	}
};

class KeyResult : public KeyItem{
	public:
	KeyResult(){
		val =0;
		id=ID_RESULT;
	}
};

class KeyNumber : public KeyItem{
	public:
	KeyNumber(int v){
		val=v;
		id=ID_NUMBER;
	}
};

#endif /*__KEYBOARD__ITEMS__H__*/