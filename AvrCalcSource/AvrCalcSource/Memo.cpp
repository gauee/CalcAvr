/*
* Memo.cpp
*
* Created: 2014-01-31 13:25:53
*  Author: gauee
*/

#include "Memo.h"
//#include <math.h>

MemoController::MemoController(){
	this->ssdisplayCntrlr = SSDisplay();
	this->cr = CalcResult();
};


MemoController::~MemoController(){};

void MemoController::initMemoController(){
	ssdisplayCntrlr.initSSDisplay();
	ssdisplayCntrlr.setNumberToDisplay(0);
}


void MemoController::addToMemo(CalcResult* crTemp){
	this->cr.size = crTemp->size;
	for(int i=0;i<crTemp->size;++i){
		this->cr.tableResult[i]=crTemp->tableResult[i];
	}
	saveToMemo();
}

CalcResult* MemoController::readFromMemo(){
	return &cr;
}

void MemoController::eraseFromMemo(){
	this->cr.cleanResult();
	saveToMemo();
	//rslt = 0;
	//ssdisplayCntrlr.setNumberToDisplay(3);
}

//void MemoController::recoverFromArray(CalcResult* cr){
	//int whereIsDot = 0;
	//cr->size;
	//this->rslt;
	//
	//for(int i = 0; i < cr->size; i++){
		//if(cr->tableResult[i] == '.'){
			//whereIsDot = i;
			//break;
		//}
	//}
	//
	//int c = 0;
	//for(int i = whereIsDot -1; i > -1; i--){
		//rslt += cr->tableResult[i] * pow(10,c);
		//c++;
	//}
	//
	//int u = -1;
	//for(int i = whereIsDot + 1; i < cr->size; i++){
		//rslt += cr->tableResult[i] * pow(10,u);
		//u--;
	//}
//}

void MemoController::saveToMemo(){
	ssdisplayCntrlr.setNumberToDisplay(cr.getValue());
}

void MemoController::setSSDVal(int val){
	ssdisplayCntrlr.setNumberToDisplay(val);
}

