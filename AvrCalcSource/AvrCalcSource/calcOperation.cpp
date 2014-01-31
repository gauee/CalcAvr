/*
* calcOperation.cpp
*
* Created: 2014-01-28 14:42:35
*  Author: gauee
*/

#include "CalcOperation.h"
#include "AvrCalcSource.h"
//potrzebujemy 3 pola zwiazane ze zmienymi i 2 ostatnie operatory w liscie

CalcOperation::CalcOperation(){
	cr = CalcResult();
	cleanOperators();
	cleanVariables();
	isLastVar = true;
};

CalcOperation::~CalcOperation(){
};


//obs³uga operacji dodawania
double CalcOperation::numbersAdd(double first,double second){
	return first+second;
}

double CalcOperation::numbersSub(double first,double second){
	return first-second;
}

double CalcOperation::numbersMul(double first,double second){
	return first*second;
}

double CalcOperation::numbersDiv(double first,double second){
	if(second != 0){
		return first/second;
	}
	return -0.12345;
}

void CalcOperation::cleanCalcOperation(){
	cleanOperators();
	cleanVariables();
	cr.cleanResult();
}

CalcResult* CalcOperation::getResult(){
	curOptIdx++;
	while(curOptIdx>0){
		calculate();
	}
	cr.setResult(variables[0]);
	return &cr;
}


void CalcOperation::loadCalcResult(CalcResult* cr){
	//TODO: implement.
}

void CalcOperation::addNumber(int num){
	if(!isLastVar){
		curVarIdx++;
	}
	variables[curVarIdx] *=10;
	variables[curVarIdx] += num;
	
	isLastVar=true;
}

void CalcOperation::addOperator(char opt){
	if(isLastVar){
		curOptIdx++;
		if(curOptIdx==OPT_SIZE){
			calculate();
		}
	}
	operators[curOptIdx] = opt;
	isLastVar=false;
}

void CalcOperation::cleanOperators(){
	for(int i=0;i<OPT_SIZE;++i){
		operators[i]=0;
	}
	curOptIdx=-1;
}

void CalcOperation::cleanVariables(){
	for(int i=0;i<VAR_SIZE;++i){
		variables[i]=0;
	}
	curVarIdx=0;
}

void CalcOperation::calculate(){
	if(curOptIdx==0){
		return;
	}
	int rslts[2];
	for(int i=0;i<curOptIdx;++i){
		rslts[i] = calculateResultFor(variables[i],variables[i+1],operators[i]);
	}
	if(curOptIdx==1){
		variables[0]=rslts[0];
		}else if(curOptIdx==2){
		if(isFirstOptGeater()){
			variables[0]=rslts[0];
			variables[1] = variables[2];
			operators[0] = operators[1];
			}else{
			variables[1]=rslts[1];
		}
	}

	curOptIdx--;
	operators[curOptIdx]=0;
	variables[curVarIdx]=0;
	curVarIdx--;
}

double CalcOperation::calculateResultFor(double var1,double var2,char opt){
	switch (opt){
		case '+':
		return numbersAdd(var1,var2);
		case '-':
		return numbersDiv(var1,var2);
		case '*':
		return numbersMul(var1,var2);
		case '/':
		return numbersDiv(var1,var2);
	}
}

bool CalcOperation::isFirstOptGeater(){
	int prior1 = getOperatorPrior(operators[0]);
	int prior2 = getOperatorPrior(operators[1]);
	if(prior2 > prior1){
		return false;
	}
	
	return true;
}

int CalcOperation::getOperatorPrior(char opt){
	switch(opt){
		case '+':
		case '-':
		return 1;
		case '*':
		case '/':
		return 2;
	}
}

void CalcOperation::initFromResult(){
	variables[0] = cr.getValue();
}


//dopisac do konca
