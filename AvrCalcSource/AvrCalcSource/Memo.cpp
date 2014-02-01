/*
* Memo.cpp
*
* Created: 2014-01-31 13:25:53
*  Author: gauee
*/

#include "Memo.h"
#include <math.h>

MemoController::MemoController(){
	this->ssdisplayCntrlr = SSDisplay();
};


MemoController::~MemoController(){};

void MemoController::initMemoController(){
	ssdisplayCntrlr.initSSDisplay();
}


void MemoController::addToMemo(CalcResult* cr){
	this->cr.size = cr->size;
	for(int i=0;i<cr->size;++i){
		this->cr.tableResult[i]=cr->tableResult[i];
	}
}

CalcResult* MemoController::readFromMemo(){
	return &cr;
}

void MemoController::eraseFromMemo(){
	this->cr.cleanResult();
	rslt = 0;
	ssdisplayCntrlr.setNumberToDisplay(0);
}

void MemoController::recoverFromArray(CalcResult* cr){
	int whereIsDot = 0;
	cr->size;
	this->rslt;
	
	for(int i = 0; i < cr->size; i++){
		if(cr->tableResult[i] == '.'){
			whereIsDot = i;
			break;
		}
	}
	
	int c = 0;
	for(int i = whereIsDot -1; i > -1; i--){
		rslt += cr->tableResult[i] * pow(10,c);
		c++;
	}
	
	int u = -1;
	for(int i = whereIsDot + 1; i < cr->size; i++){
		rslt += cr->tableResult[i] * pow(10,u);
		u--;
	}
}

void MemoController::saveToMemo(){
	//recoverFromArray(&this->cr);
	ssdisplayCntrlr.setNumberToDisplay(cr.getValue());
}

