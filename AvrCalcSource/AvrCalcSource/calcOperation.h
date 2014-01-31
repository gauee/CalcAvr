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
	static const int VAR_SIZE = 3;
	static const int OPT_SIZE = 2;
	double variables[VAR_SIZE];
	char operators[OPT_SIZE];
	int curVarIdx;
	int curOptIdx;
	bool isLastVar;
	
	//Methods
	double numbersAdd(double first,double second);
	double numbersSub(double first,double second);
	double numbersMul(double first,double second);
	double numbersDiv(double first,double second);
	void cleanVariables();
	void cleanOperators();
	void calculate();
	double calculateResultFor(double var1,double var2,char opt);
	bool isFirstOptGeater();
	int getOperatorPrior(char opt);
	};



#endif /*__CALC__OPERATIONS__H__*/

