/*
 * File name: LED_ON_OFF.h
 * Created by: Shashank Chandrasekaran
 * Description: This h file contains almost all standard header files, #defines and global
 *              variables.
 */

#ifndef LED_ON_OFF_H_
#define LED_ON_OFF_H_

#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL25Z4.h"
#include "fsl_debug_console.h"

#define RED_LED_PIN (18) //Defining PTB18 for Red LED
#define GREEN_LED_PIN (19) //Defining PTB19 for Green LED
#define BLUE_LED_PIN (1) //Defining PTD1 for Blue LED
#define RED (1) //Flag to indicate capacitive touch in Red LED region
#define GREEN (2) //Flag to indicate capacitive touch in Green LED region
#define BLUE (3) //Flag to indicate capacitive touch in Blue LED region
#define MASK(x) (1U << x) //Macro for bitwise left shift operations

extern int whiteLED; //Flag to indicate if White LED needs to glow or not
extern int touch_scan; //Captures return value from Touch_Scan function
extern int prev_touch_scan; //Store's last capacitive touch scan value

/*********LED ports initialization function****/
void LED_Init(void);

/*********Function to on LED if TSI is detected****/
void LED_ON(void); //Function to on LED

/*********Function to off LED****/
void LED_OFF(void); //Function to off LED


#endif /* LED_ON_OFF_H_ */
