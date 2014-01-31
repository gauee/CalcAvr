/*
* CalcResult.cpp
*
* Created: 2014-01-31 14:32:35
*  Author: gauee
*/


#include "CalcResult.h"

CalcResult::CalcResult(){};

CalcResult::~CalcResult(){};

void CalcResult::cleanResult(){
	for(int i=0;i<CALC_RESULT_SIZE;++i){
		tableResult[i] = 0;
	}
	size = 0;
};