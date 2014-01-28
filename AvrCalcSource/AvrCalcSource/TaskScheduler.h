/*
 * TaskScheduler.h
 *
 * Created: 2014-01-28 14:09:28
 *  Author: gauee
 */ 
#ifndef TASK_SCHEDULER_H_
#define TASK_SCHEDULER_H_

#include <avr/io.h>

#define SCHEDULER_SIZE 10			//Size of TaskArray Scheduler
typedef void (*TASK_PTR)(void);

typedef struct {
	
	TASK_PTR task_ptr;
	uint16_t to_go;
	uint16_t inteval;
	uint8_t ready;
	
} TASK;

TASK scheduled_task[SCHEDULER_SIZE];


void increment(void);			//Simple function which increment toInc;
void incrementOneShot(void);	//Simple function which should increment toInc only one time.

void init();					//Init all arrays and variables
void start_timer();				//Init TIMER0,activate interrupts and run Timer
void add_task(TASK_PTR t,int ms);		//Add periodical task
void add_one_shot(TASK_PTR t,int ms);	//Add noperiodical task which should be executed only one time.
void schedule();				//Method executes in every interrupt checking task array and setting parameters
void execute();					//Method executes all time, this method checking which task can be execute and calling method from reference in struct TASK 

#endif /* TASK_SCHEDULER_H_ */