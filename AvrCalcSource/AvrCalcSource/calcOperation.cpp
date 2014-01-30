/*
* calcOperation.cpp
*
* Created: 2014-01-28 14:42:35
*  Author: gauee
*/

#include "calcOperation.h"
#include "AvrCalcSource.h"
CalcResult rslt = CalcResult();

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

void CalcResult::cleanCalcOperation(){
	rslt.first_variable = 0;
	rslt.second_variable = 0;
	rslt.third_variable = 0;
	rslt.operator1 = 0;
	rslt.operator2 = 0;
	
	for (int i = 0; i< 8; i++)
	{
		rslt.tableResult[i] = 0;
	}
	
	
}

void CalcResult::addToMemo(){
	
	for(int i = 0 ; i < 8 ; i++){
		
		rslt.tableMemo[i] = rslt.tableResult[i];
		
	}
	
}

void CalcResult::readMemo(){
	
	for(int i = 0 ; i < 8 ; i++){
		
		rslt.tableResult[i] = rslt.tableMemo[i];
		
	}
	
}

void CalcResult::eraseMemo(){
	
	for(int i = 0 ; i < 8 ; i++){
		
		rslt.tableMemo[i] = 0;
		
	}
	
}

CalcResult getResult(){
	return rslt;
}

//dopisac do konca
