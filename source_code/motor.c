#include <avr/io.h>
#include "motor.h"

void motor_init(void){
      DDRD|=LEFT_FWD|RIGHT_FWD|LEFT_BK|RIGHT_BK;
}

void motor_logic(int side,int dir,int val){
	if(dir==FWD){
		if (val==ON){
			if (side==LEFT){
				PORTD|=(1<<1);
			}
			else if(side==RIGHT){	
				PORTD=PORTD|RIGHT_FWD;
			}
		}
		else if(val==OFF){
			if (side==LEFT){
				PORTD&=~(LEFT_FWD);
			}
			else if(side==RIGHT){
				PORTD&=~(RIGHT_FWD);
			}
		}
	}
	
	else if(dir==BK){

		if (val==ON){
			if (side==LEFT){
				PORTD|=LEFT_BK;
			}
			else if(side==RIGHT){	
				PORTD|=RIGHT_BK;
			}
		}
		else if(val==OFF){
			if (side==LEFT){
				PORTD&=~(LEFT_BK);
			}
			else if(side==RIGHT){
				PORTD&=~(RIGHT_BK);
			}
		}
			
	}
}

	
void motor_stop(void){
	
	motor_logic(LEFT,FWD,0);
	motor_logic(RIGHT,FWD,0);
	motor_logic(LEFT,BK,0);
	motor_logic(RIGHT,BK,0);
}
	
	
void motor_forward(void){
	
	motor_logic(LEFT,FWD,1);
	motor_logic(RIGHT,FWD,1);
	motor_logic(LEFT,BK,0);
	motor_logic(RIGHT,BK,0);
}

void motor_backward(void){
	
	motor_logic(LEFT,FWD,0);
	motor_logic(RIGHT,FWD,0);
	motor_logic(LEFT,BK,1);
	motor_logic(RIGHT,BK,1);
}
void motor_pivot_left(void){
	
	motor_logic(LEFT,FWD,0);
	motor_logic(RIGHT,FWD,1);
	motor_logic(LEFT,BK,1);
	motor_logic(RIGHT,BK,0);
}
	

void motor_pivot_right(void){
	
	motor_logic(LEFT,FWD,1);
	motor_logic(RIGHT,FWD,0);
	motor_logic(LEFT,BK,0);
	motor_logic(RIGHT,BK,1);
}
	
	
	
	


	
	
