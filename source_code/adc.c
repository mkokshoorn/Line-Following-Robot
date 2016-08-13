/* ADC
 * 8-bit adc, value from 0 to 255.
 *
 * make & atmega8-1-load test1.hex
 */

#include <avr/io.h>
#include <stdint.h>
#include <avr/interrupt.h>
#include "adc.h"
#include "led.h"




void adc_init(void){

	/* prescaler 8 so sample rate is 125 kHz (ideal; needs to be beteen 50 and 200 kHz)for 1 MHz clock */
	ADCSRA |= BIT(ADPS1) | BIT(ADPS0);
	/* Set reference as AVcc; need (1 uF? electro?) cap from AREF to ground */
	ADMUX |= BIT(REFS0);
	/* Turn ADC into 8 bit for easy one byte, single register reading 0-255 */
	ADMUX |= BIT(ADLAR);
	/* (0) Set ADC0 to be ADC input INITIAL CONIDITION*/
	ADMUX = MUX_ADC0;
	/* Set ADC to Free-Running mode */
	ADCSRA |= BIT(ADFR);
	/* Enable the ADC */
	ADCSRA |= BIT(ADEN);
	// Enable ADC Interrupt 
	ADCSRA |= BIT(ADIE);
	// Enable Global Interrupts 
	sei();
	/* Start the ADC measurements */
	ADCSRA |= BIT(ADSC);
	
}




