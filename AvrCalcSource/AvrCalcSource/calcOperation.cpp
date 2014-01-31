/*
* calcOperation.cpp
*
* Created: 2014-01-28 14:42:35
*  Author: gauee
*/

#include "CalcOperation.h"
#include "AvrCalcSource.h"
//potrzebujemy 3 pola zwiazane ze zmienymi i 2 ostatnie operatory w liscie

CalcOperation::CalcOperation(){
	cr = CalcResult();
};

CalcOperation::~CalcOperation(){
};
	

//obs³uga operacji dodawania
double CalcOperation::numbersAdd(double first,double second){
	return first+second;
}

double CalcOperation::numbersSub(double first,double second){
	return first-second;
}

double CalcOperation::numbersMul(double first,double second){
	return first*second;
}

double CalcOperation::numbersDiv(double first,double second){
	if(second != 0){
		return first/second;
	}
	return -0.12345;
}

void CalcOperation::cleanCalcOperation(){
	first_variable = 0;
	second_variable = 0;
	third_variable = 0;
	operator1 = 0;
	operator2 = 0;
	
	cr.cleanResult();
	
	
}
CalcResult* CalcOperation::getResult(){
	return &cr;
}


void CalcOperation::loadCalcResult(CalcResult* cr){
	//TODO: implement.
}

//dopisac do konca
