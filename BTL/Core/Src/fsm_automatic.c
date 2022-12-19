/*
 * fsm_automatic.c
 *
 *  Created on: Nov 29, 2022
 *      Author: PC
 */

#include "fsm_automatic.h"

void fsm1_automatic_run() {
	switch (status1) {
	case INIT:
		//TODO
		setRedLed1();
		status1 = AUTO_RED;
		setTimer1(red_duration1);
		setTimer3(100);
		break;

	case AUTO_RED:
		//TODO
		setRedLed1();
		if (isTimer3Expired()) {
			setTimer3(100);
			timeCountdown1--;
			writeMess(timeCountdown1);
		}
		if (isTimer1Expired() == 1) {
			setTimer1(green_duration1);
			status1 = AUTO_GREEN;
			setTimer3(100);
			timeCountdown1 = green_duration1 / 100;
		}
		if (isButtonPressed(0)) {
			clearAllLed();
			status1 = WAIT;
			status2 = WAIT;
			status3 = MODIFY_RED1;
			clearTimer1();
			clearTimer2();
			clearTimer3();
			setTimer1(100);
			status4 = PEDESTRIAN_OFF; //debug
		}
		break;

	case AUTO_GREEN:
		//TODO
		setGreenLed1();
		if (isTimer3Expired()) {
			setTimer3(100);
			timeCountdown1--;
			writeMess(timeCountdown1);
		}
		if (isTimer1Expired() == 1) {
			setTimer1(yellow_duration1);
			status1 = AUTO_YELLOW;
			setTimer3(100);
			timeCountdown1 = yellow_duration1 / 100;
		}

		if (isButtonPressed(0)) {
			clearAllLed();
			status1 = WAIT;
			status2 = WAIT;
			status3 = MODIFY_RED1;
			clearTimer1();
			clearTimer2();
			clearTimer3();
			setTimer1(100);
			status4 = PEDESTRIAN_OFF; //debug
		}
		break;

	case AUTO_YELLOW:
		//TODO
		setYellowLed1();
		if (isTimer3Expired()) {
			setTimer3(100);
			timeCountdown1--;
			writeMess(timeCountdown1);
		}
		if (isTimer1Expired() == 1) {
			setTimer1(red_duration1);
			status1 = AUTO_RED;
			setTimer3(100);
			timeCountdown1 = red_duration1 / 100;
		}

		if (isButtonPressed(0)) {
			clearAllLed();
			status1 = WAIT;
			status2 = WAIT;
			status3 = MODIFY_RED1;
			clearTimer1();
			clearTimer2();
			clearTimer3();
			setTimer1(100);
			status4 = PEDESTRIAN_OFF; //debug
		}
		break;

	case WAIT:
		if(returnFlag1){
			returnFlag1 = 0;
			status1 = INIT;
		}
		break;
	default:
		break;
	}
}

void fsm2_automatic_run() {
	switch (status2) {
	case INIT:
		//TODO
		setGreenLed2();
		status2 = AUTO_GREEN;
		setTimer2(green_duration2);
		timeCountdown2 = green_duration2 / 100;
		break;

	case AUTO_RED:
		//TODO
		setRedLed2();
		if (isTimer2Expired() == 1) {
			setTimer2(green_duration2);
			status2 = AUTO_GREEN;
			timeCountdown2 = green_duration2 / 100;
		}

		break;

	case AUTO_GREEN:
		//TODO
		setGreenLed2();
		if (isTimer2Expired() == 1) {
			setTimer2(yellow_duration2);
			status2 = AUTO_YELLOW;
			timeCountdown2 = yellow_duration2 / 100;
		}
		break;

	case AUTO_YELLOW:
		//TODO
		setYellowLed2();
		if (isTimer2Expired() == 1) {
			setTimer2(red_duration2);
			status2 = AUTO_RED;
			timeCountdown2 = red_duration2 / 100;
		}
		break;

	case WAIT:
		if(returnFlag2){
			status2 = INIT;
			returnFlag2 = 0;
		}
		break;
	default:
		break;
	}
}
