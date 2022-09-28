/**
 * File name: BLINKINGLIGHTS.c
 * Created by: Shashank Chandrasekaran
 * Description: This is the file where main() is present and it executes the logic
 * Build and compiled on: MCUXpresso IDE v11.6.0 [Build 8187] [2022-07-13]
 */

#include "LED_ON_OFF.h"
#include "TSI.h"
#include "DELAY.h"
#include "STARTUP_INF.h"

/****************************************Main function***************************************/
int main(void)
{
	/* Initialize board hardware. */
	BOARD_InitBootPins();
	BOARD_InitBootClocks();
	BOARD_InitBootPeripherals();
#ifndef BOARD_INIT_DEBUG_CONSOLE_PERIPHERAL
	/* Initialize FSL debug console. */
	BOARD_InitDebugConsole();
#endif

	/* Execution of the entire LED on and off logic by calling functions */
	LED_Init(); //Call initialization function of LED Port pins
	Touch_Init(); //Call initialization function of TSI
	startup(); //Call startup function to start sequence of LEDs
	infinite_loop(); //Call infinite loop for sequence of LEDs based on TSI
}
