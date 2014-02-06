/*
* Memo.h
*
* Created: 2014-01-31 13:18:56
*  Author: gauee
*/

#ifndef __MEMO__CONTROLLER__H__
#define __MEMO__CONTROLLER__H__

#include "CalcResult.h"
#include "SSDispaly.h"
#include "KeyItems.h"

static int MEMO_WRITE=2;
static int MEMO_READ=3;
static int MEMO_ERASE=4;

class MemoController
{

	public:
	MemoController();
	~MemoController();
	
	void initMemoController();
	void addToMemo(CalcResult* cr);
	CalcResult* readFromMemo();
	void eraseFromMemo();
	void saveToMemo();
	void setSSDVal(int val);
	
	static bool isMemoWrite(KeyItem* item){
		return item->getVal() == MEMO_WRITE;
	};
	static bool isMemoRead(KeyItem* item){
		return item->getVal() == MEMO_READ;
	};
	static bool isMemoErase(KeyItem* item){
		return item->getVal() == MEMO_ERASE;
	};
	
	protected:
	private:
	double rslt;
	CalcResult cr;
	SSDisplay ssdisplayCntrlr;
	void recoverFromArray(CalcResult* cr);
};


#endif