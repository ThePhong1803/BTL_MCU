/*
 * timer.h
 *
 *  Created on: Nov 29, 2022
 *      Author: PC
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

#include "main.h"

void setTimer0(int duration);
void setTimer1(int duration);
void setTimer2(int duraiotn);
void setTimer3(int duration);
void setTimer4(int duration);
void setTimer5(int duration); //for expired pedestrian
void setTimer6(int duration); //for buzzer


void clearTimer0();
void clearTimer1();
void clearTimer2();
void clearTimer3();
void clearTimer4();
void clearTimer5();
void clearTimer6();

int isTimer0Expired();
int isTimer1Expired();
int isTimer2Expired();
int isTimer3Expired();
int isTimer4Expired();
int isTimer5Expired();
int isTimer6Expired();

void timerRun();

#endif /* INC_TIMER_H_ */
