/*
 * global.h
 *
 *  Created on: Nov 29, 2022
 *      Author: PC
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"
#include "timer.h"
#include "input_reading.h"
#include "string.h"
#include "stdio.h"
//#define HARDWARE

#define INIT 		1
#define AUTO_RED 	2
#define AUTO_YELLOW 3
#define AUTO_GREEN  4
#define ALLOW		5
#define NOT_ALLOW	6

#define MODIFY_RED1			12
#define MODIFY_YELLOW1  	13
#define MODIFY_GREEN1   	14
#define MODIFY_RED2         15
#define MODIFY_YELLOW2		16
#define MODIFY_GREEN2		17

#define WAIT				18
#define PEDESTRIAN_RUN_ALLOW 19
#define PEDESTRIAN_RUN_NOT_ALLOW 20
#define PEDESTRIAN_OFF 21

extern UART_HandleTypeDef huart2;
extern TIM_HandleTypeDef htim3;

extern int timeCountdown1;
extern int timeCountdown2;

extern int status1;
extern int lastState1;

extern int status2;
extern int lastState2;

extern int status3;

extern int returnFlag1;
extern int returnFlag2;

extern int mode;
extern int time_input;

extern int red_duration1;
extern int yellow_duration1;
extern int green_duration1;

extern int red_duration2;
extern int yellow_duration2;
extern int green_duration2;

extern int * set1;
extern int * set2;

extern int status4;
extern int state;
extern int state2;

extern int counter_toggle;

void systemInit();
void writeMess(int time);
void writeMessage(char * str);
extern char str[64];

#endif /* INC_GLOBAL_H_ */
