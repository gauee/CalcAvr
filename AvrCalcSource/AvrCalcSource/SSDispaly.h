/*
* SSDispaly.h
*
* Created: 2014-01-28 14:12:24
*  Author: gauee
*/
#ifndef SSDISPLAY_H_
#define SSDISPLAY_H_

#include <avr/io.h>

class SSDisplay
{
	public:
	SSDisplay();
	~SSDisplay();
	void initSSDisplay();
	void setNumberToDisplay(int val);
	static void showNextDigit(void);
	
	private:
	//Variables
	int powVal;
	//Methods
	void initPortB();
	void initPortD();
};


#endif /* SSDISPLAY_H_ */