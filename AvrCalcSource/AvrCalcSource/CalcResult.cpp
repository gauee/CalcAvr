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
	this->size = 0;
	if(toSetRslt<0){
		toSetRslt*=-1;
		this->tableResult[this->size++]='-';
	}
	int firstPart = toSetRslt;
	if(firstPart == 0){
		this->tableResult[this->size++]='0';
		if(toSetRslt>0){
			caclFractionalPart(toSetRslt);
		}
		return;
	}
	
	unsigned long tenPow = 1;
	while(tenPow > 0 && firstPart>=tenPow){
		tenPow*=10;
	}
	int tmp = firstPart;
	while(tenPow>1 && this->size<CALC_RESULT_SIZE){
		tmp %= tenPow;
		tenPow/=10;
		this->tableResult[this->size++]=('0'+(tmp/tenPow));
	}
	toSetRslt -= firstPart;
	if(toSetRslt > 0 && this->size < CALC_RESULT_SIZE){
		caclFractionalPart(toSetRslt);
	}
}

void CalcResult::calcFractionalPart(double fractPart){
	this->tableResult[this->size++]='.';
	int i=0;
	while(i<2 && fractPart > 0){
		fractPart *=10;
		this->tableResult[this->size++]=('0'+(((int)fractPart)%10));
		++i;
	}
}

double CalcResult::getValue(){
	double rslt = 0;
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
			if(t == 100){
				break;
			}
		}
	}
	
	return rslt/t;
}