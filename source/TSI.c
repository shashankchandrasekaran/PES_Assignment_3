/*
 * File name: TSI.c
 * Created by: Shashank Chandrasekaran
 * Description: This c file contains TSI declaration and scan function
 * Links: https://github.com/alexander-g-dean/ESF/tree/master/NXP/Misc/Touch%20Sense.
 */

#include "TSI.h"
#include "LED_ON_OFF.h"

int scan_range[7]={85,120,125,160,165,200}; //Initializing array for storing capacitive touch ranges

/****************************************TSI Initialization function*****************************/
void Touch_Init(void)
{
	SIM->SCGC5 |= SIM_SCGC5_TSI_MASK; // enabling the clock
	TSI0->GENCS = TSI_GENCS_MODE(0u) | //operating in non-noise mode
				  TSI_GENCS_REFCHRG(0u) | //reference oscillator charge and discharge value 500nA
			      TSI_GENCS_DVOLT(0u) | //oscillator voltage rails set to default
			      TSI_GENCS_EXTCHRG(3u) | //electrode oscillator charge and discharge value 4uA
			      TSI_GENCS_PS(0u) | // frequency clock divided by one
			      TSI_GENCS_NSCN(31u) | //scanning the electrode 32 times
			      TSI_GENCS_TSIEN_MASK | //enabling the TSI module
			      TSI_GENCS_EOSF_MASK; // writing one to clear the end of scan flag
}


/*************************************TSI Touch value function*******************************/
void Touch_Scan(void)
{
	unsigned int scan = 0;
	TSI0->DATA = TSI_DATA_TSICH(10u); //Select channel 10
	TSI0->DATA |= TSI_DATA_SWTS_MASK; //software trigger to start the scan
	while (!(TSI0->GENCS & TSI_GENCS_EOSF_MASK )); // waiting for the scan to complete 32 times
	scan = TOUCH_DATA;
	TSI0->GENCS |= TSI_GENCS_EOSF_MASK ; //writing one to clear the end of scan flag

	if(scan>=scan_range[0] && scan<=scan_range[1]) //Check if the touch is in left region(Red LED)
	{
		touch_scan=1;
		whiteLED=0;
#ifdef DEBUG
		PRINTF("\n\r SLIDER VALUE is %d\n",scan);
#endif
	}

	else if (scan>=scan_range[2] && scan<=scan_range[3]) //Check if the touch is in center region(Green LED)
	{
		touch_scan=2;
		whiteLED=0;
#ifdef DEBUG
		PRINTF("\n\r SLIDER VALUE %d\n",scan);
#endif
	}

	else if (scan>=scan_range[4] && scan<=scan_range[5]) //Check if the touch is in right region(Blue LED)
	{
		touch_scan=3;
		whiteLED=0;
#ifdef DEBUG
		PRINTF("\n\r SLIDER VALUE %d\n",scan);
#endif
	}
}



