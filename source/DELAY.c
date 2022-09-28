/*
 * File name: DELAY.c
 * Created by: Shashank Chandrasekaran
 * Description: This c file contains delay, on_delay and off_delay functions
 */

#include "DELAY.h"
#include "LED_ON_OFF.h"
#include "TSI.h"

/****************************************Loop for delay**************************************/
void delay(int iterations)
{
	while(iterations--);
}

/****************************************On delay function**********************************/
void On_delay(int n)
{
	int i;
	for (i=0;i<n;i++)
	{
		delay(MS_100);
		Touch_Scan();  //Polling every 100 Ms
		LED_ON(); //On respective LED based on scan result
		prev_touch_scan=touch_scan; //Store previous scan result
	}
}

/****************************************Off delay function**********************************/
void Off_delay(int n)
{
	int i;
	for (i=0;i<n;i++)
	{
		delay(MS_100);
		Touch_Scan(); //Polling every 100 Ms
	}
}


