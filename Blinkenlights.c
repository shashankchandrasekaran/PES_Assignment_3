/*
 * @file    Blinkenlights.c
 * Created by Shashank Chandrasekaran
 * Referenced https://github.com/alexander-g-dean/ESF/blob/master/NXP/Code/Chapter_2/Source/main.c
 *            https://github.com/alexander-g-dean/ESF/tree/master/NXP/Misc/Touch Sense
 */
#include "Blinkenlights.h"
int main(void)
{
	int i,pol_flag; //Variable for loop
	SIM->SCGC5 |= (SIM_SCGC5_PORTB_MASK|SIM_SCGC5_PORTD_MASK|SIM_SCGC5_TSI_MASK ); //Set clock for Port B and D pins
	TSI0->GENCS = TSI_GENCS_MODE(0u) | //operating in non-noise mode
			TSI_GENCS_REFCHRG(0u) | //reference oscillator charge and discharge value 500nA
			TSI_GENCS_DVOLT(0u) | //oscillator voltage rails set to default
			TSI_GENCS_EXTCHRG(0u) | //electrode oscillator charge and discharge value 500nA
			TSI_GENCS_PS(0u) |  // frequency clcok divided by one
			TSI_GENCS_NSCN(31u) | //scanning the electrode 32 times
			TSI_GENCS_TSIEN_MASK | //enabling the TSI module
			TSI_GENCS_EOSF_MASK; // writing one to clear the end of scan flag
	TSI0->DATA = TSI_DATA_TSICH(9u); // selecting channel 9
	PORTB->PCR[RED_LED_PIN] &= ~PORT_PCR_MUX_MASK; //Set Red LED port pin to GPIO
	PORTB->PCR[RED_LED_PIN] |= PORT_PCR_MUX(ONE);
	PORTB->PCR[GREEN_LED_PIN] &= ~PORT_PCR_MUX_MASK; //Set Green LED port pin to GPIO
	PORTB->PCR[GREEN_LED_PIN] |= PORT_PCR_MUX(ONE);
	PORTD->PCR[BLUE_LED_PIN] &= ~PORT_PCR_MUX_MASK; //Set Blue LED port pin to GPIO
	PORTD->PCR[BLUE_LED_PIN] |= PORT_PCR_MUX(ONE);
	PTB->PDDR |= (ONE << RED_LED_PIN); //Set Red LED port pin to output
	PTB->PDDR |= (ONE << GREEN_LED_PIN); //Set Green LED port pin to output
	PTD->PDDR |= (ONE << BLUE_LED_PIN); //Set Blue LED port pin to output
	PTB->PSOR |= (ONE << GREEN_LED_PIN); //Set PTB19 for green LED to be off
	PTD->PSOR |= (ONE << BLUE_LED_PIN); //Set PTD1 for blue LED to be off
	PTB->PCOR |= (ONE << RED_LED_PIN); //Clear PTB18 to on red LED
	delay(MS_500); //500 Ms on Delay
	PTB->PSOR |= (ONE << RED_LED_PIN); //Set PTB18 to off red LED
	delay(MS_100); //100 Ms off delay
	PTB->PCOR |= (ONE << GREEN_LED_PIN); //Clear PTB19 to on green LED
	delay(MS_500); //500 Ms on delay
	PTB->PSOR |= (ONE << GREEN_LED_PIN); //Set PTB19 to off green LED
	delay(MS_100); //100 Ms off delay
	PTD->PCOR |= (ONE << BLUE_LED_PIN); //Clear PTD1 to on blue LED
	delay(MS_500); //500 Ms on delay
	PTD->PSOR |= (ONE << BLUE_LED_PIN); //Set PTD1 to off blue LED
	delay(MS_100); //100 Ms off delay
	for(i=0;i<2;i++) //Loop to blink white LED twice
	{
		PTB->PCOR |= (ONE << RED_LED_PIN)|(ONE << GREEN_LED_PIN);
		PTD->PCOR |= (ONE << BLUE_LED_PIN); //Clear RGB pins for white LED
		delay(MS_500);//500 Ms on Delay
		PTB->PSOR |= (ONE << RED_LED_PIN)|(ONE << GREEN_LED_PIN);
		PTD->PSOR |= (ONE << BLUE_LED_PIN); //Set RGB pins for white LED
		delay(MS_100); //100 Ms off delay
	}
	while(1) //infinite loop to blink white LED at different on-off delays
	{
		pol_flag=polling();
		previous_flag=pol_flag;
		if(pol_flag!=0)
		{
			iswhite=0;
		}
		LED_ON(pol_flag);
		pol_flag=pol_delay(5); //500 ms on delay
		LED_OFF(pol_flag);
		pol_flag=pol_delay(5); //500 ms off delay

		pol_flag=pol_delay(10); //1000 ms on delay
		pol_flag=pol_delay(5); //500 ms off delay

		pol_flag=pol_delay(20); //2000 ms on delay
		pol_flag=pol_delay(5); //500 ms off delay

		pol_flag=pol_delay(30); //3000 ms on delay
		pol_flag=pol_delay(5); //500 ms off delay
	}
}
