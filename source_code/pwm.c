#include <avr/io.h>
#include "pwm.h"

void pwm_init (void){

	/* PB1 as output */
	DDRB = BIT(DDB3);
	
	/* Assign PWM to PB3 using Timer2 */
	TCCR2 = BIT(WGM20) | BIT(WGM21)  /* Fast PWM mode */
	        | BIT(COM21)             /* Clear OC2 on Compare Match */
	        | BIT(CS21);             /* 1/8 prescale = 488 Hz */
    
	OCR2 = 0x80;

}
