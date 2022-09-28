/*
 * File name: DELAY.h
 * Created by: Shashank Chandrasekaran
 * Description: This h file contains #defines for MS counts and delay function declarations
 */

#ifndef DELAY_H_
#define DELAY_H_

#define MS_100 (600962) // count for 100ms delay
#define MS_500 (3004808)  // count for 500ms delay

void delay(int iterations); //Simple delay function

void On_delay(int n); //On delay function to poll Touch_scan function every 100 Ms and change LED color if touch detected

void Off_delay(int n); //Off delay function to poll Touch_scan function every 100 Ms

#endif /* DELAY_H_ */
