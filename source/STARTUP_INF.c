/*
 * File name: STARTUP_INF.c
 * Created by: Shashank Chandrasekaran
 * Description: This c file contains the LED startup and infinite loop sequence logic functions
 */

#include "STARTUP_INF.h"
#include "LED_ON_OFF.h"
#include "TSI.h"
#include "DELAY.h"

/****************************************LED startup function********************************/
void startup(void)
{
	int i;
	PTB->PCOR |= MASK(RED_LED_PIN); //Clear PTB18 to on red LED
	delay(MS_500);
	PTB->PSOR |= MASK(RED_LED_PIN); //Set PTB18 to off red LED
	delay(MS_100);

	PTB->PCOR |= MASK(GREEN_LED_PIN); //Clear PTB19 to on green LED
	delay(MS_500);
	PTB->PSOR |= MASK(GREEN_LED_PIN); //Set PTB19 to off green LED
	delay(MS_100);

	PTD->PCOR |= MASK(BLUE_LED_PIN); //Clear PTD1 to on blue LED
	delay(MS_500);
	PTD->PSOR |= MASK(BLUE_LED_PIN); //Set PTD1 to off blue LED
	delay(MS_100);

	for(i=0;i<2;i++) //Blinking White LED  2 times for 100ms
	{
		PTB->PCOR |= MASK(RED_LED_PIN)|MASK(GREEN_LED_PIN); //All pins R,G,B cleared to on White LED
		PTD->PCOR |= MASK(BLUE_LED_PIN);
		delay(MS_100);
		PTB->PSOR |= MASK(RED_LED_PIN)|MASK(GREEN_LED_PIN); //All pins R,G,B set to off White LED
		PTD->PSOR |= MASK(BLUE_LED_PIN);
		delay(MS_100);
	}
}

/****************************************Infinite Loop function*******************************/
void infinite_loop(void)
{
	while(1)
	{
		LED_ON();
		On_delay(5); //500 mSec on delay
		LED_OFF();
		Off_delay(5); //500 mSec off delay

		LED_ON();
		On_delay(10); //1000 mSec on delay
		LED_OFF();
		Off_delay(5); //500 mSec off delay

#ifdef DEBUG
		PRINTF("\n\r START TIMER 2000 \n");
#endif
		LED_ON();
		On_delay(20); //2000 mSec on delay
		LED_OFF();
		Off_delay(5); //500 mSec off delay

		LED_ON();
		On_delay(30); //3000 mSec on delay
		LED_OFF();
		Off_delay(5); //500 mSec off delay
	}
}
