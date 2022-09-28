/*
 * File name: TSI.h
 * Created by: Shashank Chandrasekaran
 * Description: This h file contains #defines, global variable and touch initialization
 *              and scan function definitions
 */

#ifndef TSI_H_
#define TSI_H_

#define TOUCH_DATA (TSI0->DATA & 0xFFFF) //To store exact scan value

extern int scan_range[7]; //Array for storing capacitive touch ranges


/********Function for initialization of TSI register**********/
void Touch_Init(void);

/***********Function to scan value from TSI*******************/
void Touch_Scan(void);


#endif /* TSI_H_ */
