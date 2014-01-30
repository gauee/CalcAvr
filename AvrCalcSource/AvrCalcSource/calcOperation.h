/*
* calcOperation.h
*
* Created: 2014-01-28 14:08:50
*  Author: gauee
*/
#ifndef __CALC__OPERATIONS__H__
#define __CALC__OPERATIONS__H__


class CalcResult{
	public:
	int size;
	char tableResult [8];
	char tableMemo[8];
	void cleanCalcOperation();
	void addToMemo();
	void readMemo();
	void eraseMemo();
	double first_variable;
	double second_variable;
	double third_variable;
	char operator1;
	char operator2;
	
};

double numbersAdd(double first,double second);
double numbersSub(double first,double second);
double numbersMul(double first,double second);
double numbersDiv(double first,double second);
CalcResult getResult();


#endif /*__CALC__OPERATIONS__H__*/

