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
	//TODO: implement.
	this->cr = *cr;
}
	
CalcResult* MemoController::readFromMemo(){
	//TODO: implement.
	return &cr;	
}

void MemoController::eraseFromMemo(){
	//TODO: implement.
	this->cr.cleanResult();
}