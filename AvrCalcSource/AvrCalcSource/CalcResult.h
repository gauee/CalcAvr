/*
 * CalcResult.h
 *
 * Created: 2014-01-31 13:22:53
 *  Author: gauee
 */ 
#ifndef __CALC__RESULT__H__
#define __CALC__RESULT__H__

#define CALC_RESULT_SIZE 8

class CalcResult{
	
	public:
	CalcResult();
	~CalcResult();
	int size;
	char tableResult [CALC_RESULT_SIZE];
	void cleanResult();
	
};

#endif /*__CALC__RESULT__H__*/