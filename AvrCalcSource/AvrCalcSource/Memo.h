/*
 * Memo.h
 *
 * Created: 2014-01-31 13:18:56
 *  Author: gauee
 */ 

#ifndef __MEMO__CONTROLLER__H__
#define __MEMO__CONTROLLER__H__

#include "CalcResult.h"
#include "KeyItems.h"

static int MEMO_WRITE=1;
static int MEMO_READ=2;
static int MEMO_ERASE=3;

class MemoController
{
public:
 MemoController();
 ~MemoController();
 
 void initMemoController();
 void addToMemo(CalcResult* cr);
 CalcResult* readFromMemo();
 void eraseFromMemo();
 
 static bool isMemoWrite(KeyItem* item){
	 return item->getVal() == MEMO_WRITE;
 }
 static bool isMemoRead(KeyItem* item){
	 return item->getVal() == MEMO_READ;
 }
 static bool isMemoErase(KeyItem* item){
	 return item->getVal() == MEMO_ERASE;
 }
 
 
 
protected:
private:
	CalcResult cr;
};


#endif