/* intersection.c
 *
 * Program to make intersection decisions and turning for line following robot.
 * 
 * Created: 04/07/2012 
 * Author: Gavin Austin
 *
 */ 



#include <avr/io.h>
#include "motor.h"
#include "timer.h"
#include "intersection.h"



void T_intersection(void){
	while (~left && ~right){
		motor_stop();
		
	}
	int rand = 0;
	if (middle){
		//number 0 to 2
		rand = 0;
	}
	else {
		//number 0 or 1
		rand = 1;
	}
	
	
	if (rand == 0){
		turn_left();
	}
	else if (rand == 1){
		turn_right();
	}
	else if (rand == 2){
		go_straight();
	}
	
}


void left_intersection(void){
	while (left){
		motor_stop();
		
	}
	if (middle){
		//number 0 to 1
		int rand = 0;
		if (rand == 0){
			turn_left();
		}
		else if (rand == 1){
			go_straight();
		}
	}
	else {
		turn_left();
	}
		
}

void right_intersection(void){
	while (left){
		motor_stop();
		
	}
	if (middle){
		//number 0 to 1
		int rand = 0;
		if (rand == 0){
			turn_right();
		}
		else if (rand == 1){
			go_straight();
		}
	}
	else {
		turn_right();
	}
		
}

void turn_left(void){
	motor_pivot_left();
	delay_1sec();
	motor_forward();
	delay_1sec();
	
}

void turn_right(void){
	motor_pivot_left();
	delay_1sec();
	motor_forward();
	delay_1sec();
}

void go_straight(void){
	motor_forward();
	delay_1sec();
}
