/*
 * Memo.cpp
 *
 * Created: 2014-01-31 13:25:53
 *  Author: gauee
 */ 

#include "Memo.h"

MemoController::MemoController(){};

MemoController::~MemoController(){};
	
void MemoController::addToMemo(CalcResult* cr){
	this->cr.size = cr->size;
	for(int i=0;i<cr->size;++i){
		this->cr.tableResult[i]=cr->tableResult[i];
	}
}
	
CalcResult* MemoController::readFromMemo(){
	//TODO: implement.
	return &cr;
}

void MemoController::eraseFromMemo(){
	//TODO: implement.
	this->cr.cleanResult();
	rslt = 0;
}
