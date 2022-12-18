/*
 * global.h
 *
 *  Created on: Nov 29, 2022
 *      Author: PC
 */


#include "global.h"

int status1 = INIT;
int lastState1 = INIT;

int status2 = INIT;
int lastState2 = INIT;

int status3 = WAIT;

int red_duration1    = 500; //5 seconds
int yellow_duration1 = 200; //2 seconds
int green_duration1  = 300; //3 seconds

int red_duration2    = 500; //5 seconds
int yellow_duration2 = 200; //2 seconds
int green_duration2  = 300; //3 seconds

int time_input = 1;
int mode = 1;

int timeCountdown1 = 0;
int timeCountdown2 = 0;

int returnFlag1 = 0;
int returnFlag2 = 0;

int status4 = PEDESTRIAN_OFF;
int state = 0;
int state2 = 0;
int counter_toggle = 0;
//>>>>
//void writeMess(int time){
//	char str[32];
//	sprintf((char*) str, "!7SEG:%02d#\r\n", time);
//	HAL_UART_Transmit(&huart2, (uint8_t *)str, strlen(str), 10);
//}
//void writeMessage(char * str){
//	HAL_UART_Transmit(&huart2, (uint8_t *)str, strlen(str), 10);
//}
//>>>>
