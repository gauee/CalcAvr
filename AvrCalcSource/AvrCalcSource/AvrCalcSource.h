/*
 * AvrCalcSource.h
 *
 * Created: 2014-01-28 14:52:50
 *  Author: gauee
 */ 
#ifndef __AVR__CALC__SOURCE__H__
#define __AVR__CALC__SOURCE__H__

#include <avr/io.h>
#include "KeyItems.h"

void initAvrCalc();

//Obsługa LCD
void cleanCalculation();
void printCalculation(char *);

//Obsługa SSD
void saveLastResultInMemo(double rslt);
void cleanLastResultInMemo();
double getLastResultFromMemo();

//Obsługa Klawiatury
void readPressedKey();
void appendKeyItem(KeyItem item);

//Obsługa Portu szeregowego
int readCharFromSerialPort();
void printToSerialPort(char c);

//Obsługa Kalkulatora
double calcResult();
void cleanResults();
char getOperator(int iter);

//Osbluga lancucha operacji
void appendOperator(KeyItem optr);
void appendNumber(KeyItem number);
void handleMemo(KeyItem memo);


#endif /*__AVR__CALC__SOURCE__H__*/