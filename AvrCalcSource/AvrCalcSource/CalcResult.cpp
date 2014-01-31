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

void CalcResult::setResult(double toSetRslt){
	int firstPart = toSetRslt;
	int tenPow = 1;
	int curSize=0;
	while(firstPart>tenPow){
		tenPow*=10;
	}
	int tmp = firstPart;
	while(tenPow>1 && curSize<CALC_RESULT_SIZE){
		tmp %= tenPow;
		tenPow/=10;
		this->tableResult[curSize++]=('0'+(tmp/tenPow));
	}
	if((toSetRslt-firstPart)>0 && curSize < CALC_RESULT_SIZE){
		this->tableResult[curSize++]='.';
		double secondPart = (toSetRslt-firstPart)*10;
		while(curSize<CALC_RESULT_SIZE && secondPart>0){
			this->tableResult[curSize++]=('0'+((int)secondPart));
		}
	}
	this->size=curSize;
}

double CalcResult::getValue(){
	double rslt =0;
	int scale = 10;
	int t=1;
	bool isPart = false;
	for(int i=0;i<this->size;++i){
		if(this->tableResult[i] == '.'){
			isPart = true;
			continue;
		}
		rslt *=scale;
		rslt += (this->tableResult[i]-'0');
		if(isPart){
			t*=scale;
		}
		
	}
	
	return rslt/t;
}