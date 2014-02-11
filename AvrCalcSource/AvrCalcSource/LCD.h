/*
* LCDCntrlr.h
*
* Created: 2014-01-31 13:28:33
*  Author: gauee
*/

#ifndef __LCD__CONTROLLER__H__
#define __LCD__CONTROLLER__H__

#include "CalcResult.h"

class LCDController
{
	public:
	LCDController();
	~LCDController();
	
	void initLcd();
	void cleanDisplay(void);
	void loadCalcResult(CalcResult* cr);
	void writeCalcResult(CalcResult* cr);
	void addOperator(char opt);
	void addNumber(int num);

	protected:
	private:
	//Variables
	static const int MAX_CALC_OPER_SIZE = 128;
	char calcOperStr[MAX_CALC_OPER_SIZE];
	int curIdx;
	bool lastWasOperator;
	//Methods	
	void displayCalcOperation();
	void displayOper(char c);
	void display(char c);
};


#endif /*__LCD__CONTROLLER__H__*/
