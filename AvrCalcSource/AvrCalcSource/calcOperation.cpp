/*
 * calcOperation.cpp
 *
 * Created: 2014-01-28 14:42:35
 *  Author: gauee
 */ 

#include <calcOperation.h>

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
