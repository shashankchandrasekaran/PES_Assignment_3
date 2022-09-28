
/*
 * File name: LED_ON_OFF.c
 * Created by: Shashank Chandrasekaran
 * Description: This c file contains LED port pins initialization function and LED ON and
 *              OFF function
 * Reference: Dean Chapter 2
 * Link:https://github.com/alexander-g-dean/ESF/blob/master/NXP/Code/Chapter_2/Source/main.c
 */

#include "LED_ON_OFF.h"

int whiteLED=1; //Flag to indicate if White LED needs to glow or not
int touch_scan=0; //Captures return value from Touch_Scan function
int prev_touch_scan=0; //Store's last capacitive touch scan value

/****************************************Port Initialization function*****************************/
void LED_Init(void)
{
	SIM->SCGC5 |= SIM_SCGC5_PORTB_MASK|SIM_SCGC5_PORTD_MASK; //Set clock for Port B and D pins

	PORTB->PCR[RED_LED_PIN] &= ~PORT_PCR_MUX_MASK; //Set Red LED port pin to GPIO
	PORTB->PCR[RED_LED_PIN] |= PORT_PCR_MUX(1);

	PORTB->PCR[GREEN_LED_PIN] &= ~PORT_PCR_MUX_MASK; //Set Green LED port pin to GPIO
	PORTB->PCR[GREEN_LED_PIN] |= PORT_PCR_MUX(1);

	PORTD->PCR[BLUE_LED_PIN] &= ~PORT_PCR_MUX_MASK; //Set Blue LED port pin to GPIO
	PORTD->PCR[BLUE_LED_PIN] |= PORT_PCR_MUX(1);

	PTB->PDDR |= MASK(RED_LED_PIN); //Set Red LED port pin to output
	PTB->PDDR |= MASK(GREEN_LED_PIN); //Set Green LED port pin to output
	PTD->PDDR |= MASK(BLUE_LED_PIN); //Set Blue LED port pin to output

	PTB->PSOR |= MASK(RED_LED_PIN); //Set PTB18 for red LED to be off on startup
	PTB->PSOR |= MASK(GREEN_LED_PIN); //Set PTB19 for green LED to be off on startup
	PTD->PSOR |= MASK(BLUE_LED_PIN); //Set PTD1 for blue LED to be off on startup
}


/****************************************LED on function**************************************/
void LED_ON(void)
{
	if(whiteLED==1) // White LED on
	{
		PTB->PCOR |= MASK(RED_LED_PIN)|MASK(GREEN_LED_PIN);
		PTD->PCOR |= MASK(BLUE_LED_PIN);
	}
	else if(touch_scan==RED) // Red LED on
	{
		PTB->PSOR |= MASK(GREEN_LED_PIN);
		PTD->PSOR |= MASK(BLUE_LED_PIN);
		PTB->PCOR |= MASK(RED_LED_PIN);
		if (prev_touch_scan!=1)
		{
#ifdef DEBUG
			PRINTF("\n\r CHANGE LED TO RED\n");
#endif
		}
	}
	else if (touch_scan==GREEN) // Green LED on
	{
		PTB->PSOR |= MASK(RED_LED_PIN);
		PTD->PSOR |= MASK(BLUE_LED_PIN);
		PTB->PCOR |= MASK(GREEN_LED_PIN);
		if (prev_touch_scan!=2)
		{
#ifdef DEBUG
			PRINTF("\n\r CHANGE LED TO GREEN\n");
#endif
		}
	}
	else if(touch_scan==BLUE) // Blue LED on
	{
		PTB->PSOR |= MASK(RED_LED_PIN);
		PTB->PSOR |= MASK(GREEN_LED_PIN);
		PTD->PCOR |= MASK(BLUE_LED_PIN);
		if (prev_touch_scan!=3)
		{
#ifdef DEBUG
			PRINTF("\n\r CHANGE LED TO BLUE\n");
#endif
		}
	}
}


/****************************************LED off function***********************************/
void LED_OFF(void)
{
	if(whiteLED==1) // White LED off
	{
		PTB->PSOR |= MASK(RED_LED_PIN)|MASK(GREEN_LED_PIN);
		PTD->PSOR |= MASK(BLUE_LED_PIN);
	}
	else if(touch_scan==RED) // Red LED off
	{
		PTB->PSOR |= MASK(RED_LED_PIN);
	}
	else if (touch_scan==GREEN) // Green LED off
	{
		PTB->PSOR |= MASK(GREEN_LED_PIN);
	}
	else if(touch_scan==BLUE) // Blue LED off
	{
		PTD->PSOR |= MASK(BLUE_LED_PIN);
	}
}

