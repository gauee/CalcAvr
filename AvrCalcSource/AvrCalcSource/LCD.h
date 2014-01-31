/*
* LCDCntrlr.h
*
* Created: 2014-01-31 13:28:33
*  Author: gauee
*/

#ifndef __LCD__CONTROLLER__H__
#define __LCD__CONTROLLER__H__

#include "CalcResult.h"

class LCDController
{
	public:
	LCDController();
	~LCDController();
	
	void cleanDisplay(void);
	void loadCalcResult(CalcResult* cr);
	void writeCalcResult(CalcResult* cr);

	protected:
	private:
};


#endif /*__LCD__CONTROLLER__H__*/
