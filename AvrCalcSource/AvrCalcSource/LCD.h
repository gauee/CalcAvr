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
	
	void cleanDisplay(void);
	void loadCalcResult(CalcResult* cr);
	void writeCalcResult(CalcResult* cr);
	void addOperator(KeyItem item);
	void addNumber(KeyItem item);

	protected:
	private:
	//Variables
	static const int MAX_CALC_OPER_SIZE = 128;
	char calcOperStr[MAX_CALC_OPER_SIZE];
	int curIdx;

	//Methods	
	void displayCalcOperation();
};


#endif /*__LCD__CONTROLLER__H__*/
