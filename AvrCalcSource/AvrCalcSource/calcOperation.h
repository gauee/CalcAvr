/*
* calcOperation.h
*
* Created: 2014-01-28 14:08:50
*  Author: gauee
*/
#ifndef __CALC__OPERATIONS__H__
#define __CALC__OPERATIONS__H__

#include "CalcResult.h"

class CalcOperation{
	public:
	CalcOperation();
	~CalcOperation();
	
	void addOperator(char op);
	void addNumber(int num);
	void loadCalcResult(CalcResult* cr);
	void cleanCalcOperation();	
	CalcResult* getResult();

	private:
	//Variables
	CalcResult cr;
	double first_variable;
	double second_variable;
	double third_variable;
	char operator1;
	char operator2;
	//Methods
	double numbersAdd(double first,double second);
	double numbersSub(double first,double second);
	double numbersMul(double first,double second);
	double numbersDiv(double first,double second);
	
	};



#endif /*__CALC__OPERATIONS__H__*/

