/*
 * Keyboard.h
 *
 * Created: 2014-01-28 14:34:46
 *  Author: gauee
 */ 
#ifndef __KEYBOARD__H__
#define __KEYBOARD__H__

#include <avr/io.h>
#include "KeyItems.h"

#define MAX_OPERATORS 4

class KeyboardController{

public:
 KeyboardController();
 ~KeyboardController();

 KeyItem readValueFromKeyboard(void);

 int getNextOperator();
 void initOperatorId();

 void setKeyValue(int val);
};

#endif /* __KEYBOARD__H__ */