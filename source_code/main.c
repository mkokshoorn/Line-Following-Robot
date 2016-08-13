/* Main.c
 *
 * Created: 3/29/2012 3:26:04 PM
 * 
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "led.h"
#include "adc.h"
#include "pwm.h"
#include "motor.h"
#include "intersection.h"
#include "timer.h"

uint8_t right_sensor = 0;
uint8_t middle_sensor= 0;
uint8_t left_sensor = 0;
uint8_t choice = ADC0;


int mot = 0;
int left = 0;
int right = 0;
int middle = 1;
int intersection = 0;
int direction = 0;
int finding = 1;



int main (void){
	
		
	/* ADC */
	adc_init();   
	pwm_init();
	motor_init();
	led_on(RED);

	DUTY_CYCLE=128;  // 0-255;

	
	/* INFINITE LOOP */
	while(1){       
		
		
		
		if (left_sensor>200){
			left = 1;
			    	    	}
    	    	else{
    	    		left = 0;
    	    	}
    	    	if (right_sensor>200){
    	    		right = 1;
    	    	}
    	    	else{
    	    		right = 0;
    	    	}
    	    	if (middle_sensor>200){
	      		middle = 1;
	      		led_on(GREEN);
	      		finding = 1;
    	    	  }
    	    	else{
    	    		middle = 0;
    	    		led_off(GREEN);
    	    		
    	    	}
		
    	    	
				
		
		//detects if at intersection
		//if (left || right){
			//intersection = 1;
			//motor_stop();
		//}
		
		
		if (intersection == 0){
			
			// Deals with if middle is not black
			if (middle == 0){
				if (direction){
					
					int i = 0;
					while (i < (finding+2)){
						motor_pivot_left();
						delay_1sec();
						i++;
					}
					go_straight();
					delay_1sec();
					finding ++;
					direction = ~direction;
				}
				else{
					
					int i = 0;
					while (i < (finding+2)){
						motor_pivot_right();
						delay_1sec();
						i++;
					}
					go_straight();
					delay_1sec();
					finding ++;
					direction = ~direction;
				}
			}
			else{
				motor_forward();
				delay_1sec();
				
				
				
			}
		}
		//If at intersection
		else{
			
			if (left && right){
				T_intersection();
			}
			if (left){
				left_intersection();
			}
			if (right) {
				right_intersection();
			}
			
		}
	}
}





ISR(ADC_vect){
	    // 0 ->2; 2->1; 1->0
	  if (choice == ADC0){
		left_sensor = ADCH;
		
		/* start measuring adc1 */
		ADMUX = MUX_ADC1;
		choice = ADC1;
	  }
	  else if (choice == ADC1){
	  	right_sensor = ADCH;
	  	/* start measuring adc2 */
		ADMUX = MUX_ADC2;
		choice = ADC2;
	  }
	  else if (choice == ADC2){
	  	 middle_sensor = ADCH;
	      /* start measuring adc0 */
	      ADMUX = MUX_ADC0;
	      choice = ADC0;
	  }
}
