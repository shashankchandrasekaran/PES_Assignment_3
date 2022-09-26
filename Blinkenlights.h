/*
 * Blinkenlights.h
 *
 *  Created on: Sep 26, 2022
 *      Author: Shashank C
 */

#ifndef BLINKENLIGHTS_H_
#define BLINKENLIGHTS_H_
#include <stdio.h>
#include "board.h"
#include "MKL25Z4.h"
#define RED_LED_PIN 18 //Defining PTB18 for Red LED
#define GREEN_LED_PIN 19 //Defining PTB19 for Green LED
#define BLUE_LED_PIN 1 //Defining PTD1 for Blue LED
#define ONE 1 //Defining one for bitwise
#define MS_50 114942
#define MS_500 1149425 // count for 500ms delay
#define MS_100 229885 // count for 100ms delay
#define MS_1000 2298850 // count for 1000ms delay
#define MS_2000 4597700 // count for 2000ms delay
#define MS_3000 6896550 //count for 3000ms delay
#define TOUCH_DATA (TSI0->DATA & 0xFFFF)//macro for extracting the count from data register
int iswhite=1;
int previous_flag=0;

void delay(int iterations) //Delay loop
{
	while(iterations--);
}

int polling() //Polling function
{
	unsigned int scan_prev,scan;
	int flag=0;
	TSI0->DATA |= TSI_DATA_SWTS_MASK; //software trigger to start the scan
	while (!(TSI0->GENCS & TSI_GENCS_EOSF_MASK )); // waiting for the scan to complete 11 times
	scan_prev = TOUCH_DATA; //Read data
	delay(MS_50); //De-bouncing
	scan = TOUCH_DATA; //Read data
	TSI0->GENCS |= TSI_GENCS_EOSF_MASK ; //writing one to clear the end of scan flag
	if(scan_prev==scan)
	{
	if(scan>=610&&scan<=750)  //Data for Red LED range
	{
		PTB->PCOR |= (ONE << RED_LED_PIN);
		printf("Red LED is on: %d\n",scan);
		flag=1;
		return flag;
	}
	else if (scan>=800&&scan<=1000) //Data for green LED range
	{
		PTB->PCOR |= (ONE << GREEN_LED_PIN);
		printf("Green LED is on: %d\n",scan);
		flag=2;
		return flag;
	}
	else if (scan>=1100&&scan<=1200) //Data for Blue LED range
	{
		PTD->PCOR |= (ONE << BLUE_LED_PIN);
		printf("Blue LED is on: %d\n",scan);
		flag=3;
		return flag;
	}
	}
	return previous_flag;
}

void LED_ON(int pol_flag) //Function to on LED in infinite loop
{
	switch(pol_flag)
	{
	case 1:
		PTB->PSOR |= (ONE << GREEN_LED_PIN);
		PTD->PSOR |= (ONE << BLUE_LED_PIN);
		PTB->PCOR |= (ONE << RED_LED_PIN);
		break;
	case 2:
		PTB->PSOR |= (ONE << RED_LED_PIN);
		PTD->PSOR |= (ONE << BLUE_LED_PIN);
		PTB->PCOR |= (ONE << GREEN_LED_PIN);
		break;
	case 3:
		PTB->PSOR |= (ONE << RED_LED_PIN);
		PTB->PSOR |= (ONE << GREEN_LED_PIN);
		PTD->PCOR |= (ONE << BLUE_LED_PIN);
		break;
	}
	if(iswhite==1)
	{
		PTB->PCOR |= (ONE << RED_LED_PIN)|(ONE << GREEN_LED_PIN);
		PTD->PCOR |= (ONE << BLUE_LED_PIN);
	}
}

int pol_delay(int n) //Delay function in infinite loop
{
	int flag,i;
	for (i=0;i<n;i++)
	{
		delay(MS_100);
		flag=polling();
		previous_flag=flag;
		if(flag!=0)
		{
			iswhite=0;
		}
		LED_ON(flag);
	}
	return flag;
}

void LED_OFF(int pol_flag) //Switiching off LED
{
	switch(pol_flag)
	{
	case 1:
		PTB->PSOR |= (ONE << RED_LED_PIN);
		break;
	case 2:
		PTB->PSOR |= (ONE << GREEN_LED_PIN);
		break;
	case 3:
		PTD->PSOR |= (ONE << BLUE_LED_PIN);
		break;
	default:
		PTB->PSOR |= (ONE << RED_LED_PIN)|(ONE << GREEN_LED_PIN);
		PTD->PSOR |= (ONE << BLUE_LED_PIN);
	}
}


#endif /* BLINKENLIGHTS_H_ */
