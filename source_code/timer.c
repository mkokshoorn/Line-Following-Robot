/* timer.c
 *
 * Initialises and implements a timer.
 *  
 *
 * Created: 05/07/2012 
 * Author: Gavin Austin
 *
 */ 



#include <avr/io.h>
#include "timer.h"

void delay_1sec(){
	TCNT1=15625;
	while(TCNT1>0){
		TCNT1=(TCNT1-1);
	}
	
}

void clock_init(){
	TCCR1B = (1<<CS10)|(1<<CS11); // Clock prescaler is set to divided by 64
}