# PES_Assignment_3
PES Assignment 3
Created by Shashank Chandrasekaran

/***** Peer reveiew comments*************************************/
Reviewer - Ruthwik Chanda
Peer Review comments:
1) Multiple .C and .H files not created
2) ESE guideline #define values to be in paranthesis
3) Initalize the functions for startup, LED on, LED off and delay
4) Update logic for TSI to give correct output
5) Use separate delay functions for LED ON and OFF. Currently during off delay cycle, if touch is detected LED is glowing
6) Improve indendation in the code (Give more spaces between instructions)
7) Good commenting but add few more comments
8) Test your code in release mode
9) Add more printf statements in debug mode

Action taken : All the above points were incorporated in the latest code.

/*************Approach toward the program****************************/
- Hello world test program run on frdm board to ensure proper working of MCUXpresso IDE and board
- frdm-kl25z Datasheet and wiring diagram studied
- Calculating delay: An LED was on and immediately a delay function: random high count was set in a while loop and decremented till it reaches zero. After that LED
  was turned off.A stopwatch was used to calculate time the LED was on. This gave a relation between count and time. Thus for various delay like 100 MS, 500 MS ,
  count could be calculated
 - Calibrating capacitive touch sensor - From leftmost portion (Freescale on board), readings were taken based on register GENCS settings, then rightmost(2013 on board)
    readings were taken. These were divided into 3 regions and by hit and trail modified till an acceptable LED change was seen.
- Logic was then developed- The details can be seen in comments in source and header files


Challenges faced:
- Calibrating the capacitive touch sensor - The scan value when finger is touched on TSI and then removed doesn't drop instantly. There was a gradual drop
  in the scan value from touch value to the offset value when no touch is detected. Hence in the GENCS register, the EXTCHRG was set to 3U i.e. electrode oscillator
  charge and discahrge value increase to 4uA. This solved the problem to a gret extent.

- In the project settings, for the release mode, the optimization level was not set to none. This was optimizing code and avoiding delay funtions when running
  in release mode. It took a while to debug and with help of professor, we found out that the optimization was the problem and setting was restored to none.
  
 Note : The TSI will detect a change and glow LED if the entire width is covered with pointer finger by applying moderate pressure.
 
 The submission contains all the project contents and a video demonstarting the working of project on frdm board.




