/* led.c
 *
 * Program to initilise, toggle and turn on/off LED's.
 * also has a test led function to cycle through LED's to ensure functionality. 
 *
 * Created: 29/06/2012 
 * Author: Matt Kokshoorn
 *
 */ 



#include <avr/io.h>
#include "led.h"


void led_init(void){
	DDRB|=(1<<YELLOW)|(1<<RED)|(1<<GREEN);
	led_off(RED); led_off(GREEN); led_off(YELLOW);
}

void led_toggle(int led){
	PORTB=PORTB^(1<<led);
}

void led_on(int led){
	PORTB=PORTB&(~(1<<led));
	
}

void led_off(int led){
	PORTB=PORTB|(1<<led);
}
void test_led(void){
  volatile long i;
  volatile long j=0;
  while(1) {
  	
    if(j==1) led_on(YELLOW);   
    if(j==2) led_on(GREEN);    
    if(j==3) led_on(RED);
    if(j==4) led_off(YELLOW);
    if(j==5) led_off(GREEN);  
    if(j==6) led_off(RED);    
    if(j==7) j=0;   		        
    j++;
    for (i = 0; i < 10000; i++) continue; //delay loop
  }  
  	
}