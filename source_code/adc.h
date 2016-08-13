/* ADC
 * 8-bit adc, value from 0 to 255.
 *
 * make & atmega8-1-load test1.hex
 */

#define BIT(x) (1 << (x))


/* ADC */
#define ADC0 0
#define ADC1 1
#define ADC2 2
#define MUX_ADC0 (ADMUX & ~(BIT(MUX3) | BIT(MUX2) | BIT(MUX1) | BIT(MUX0) ) )
#define MUX_ADC1 ((ADMUX & ~(BIT(MUX3) | BIT(MUX2) | BIT(MUX1) | BIT(MUX0) ) ) | BIT(MUX0))
#define MUX_ADC2 ((ADMUX & ~(BIT(MUX3) | BIT(MUX2) | BIT(MUX1) | BIT(MUX0) ) ) | BIT(MUX1))



void adc_init(void);
