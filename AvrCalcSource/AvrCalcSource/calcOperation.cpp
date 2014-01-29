/*
* calcOperation.cpp
*
* Created: 2014-01-28 14:42:35
*  Author: gauee
*/

#include "calcOperation.h"
#include "AvrCalcSource.h"

//potrzebujemy 3 pola zwiazane ze zmienymi i 2 ostatnie operatory w liscie

//obs³uga operacji dodawania
double numbersAdd(double first,double second){
	return first+second;
}

double numbersSub(double first,double second){
	return first-second;
}

double numbersMul(double first,double second){
	return first*second;
}

double numbersDiv(double first,double second){
	if(second != 0){
		return first/second;
	}
	return -0.12345;
}

void cleanCalcOperation(){
	first_variable = 0;
	second_variable = 0;
	third_variable = 0;
	operator1 = 0;
	operator2 = 0;
	
	for (int i = 0; i< 8; i++)
	{
		tableResult[i] = 0;
	}
	
	
}

void addToMemo(){
	
	for(int i = 0 ; i < 8 ; i++){
		
		tableMemo[i] = tableResult[i];
		
	}
	
}

void readMemo(){
	
	for(int i = 0 ; i < 8 ; i++){
		
		tableResult[i] = tableMemo[i];
		
	}
	
}

void eraseMemo(){
	
	for(int i = 0 ; i < 8 ; i++){
		
		tableMemo[i] = 0;
		
	}
	
}

CalcResult::void getResult(char tab[]){
	
	for (int i = 0; i < tab.size; i++ )
	{
		
		
	}
	
	//wynik
	
}

//dopisac do konca
