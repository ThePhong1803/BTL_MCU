/*
 * fsm_manual.c
 *
 *  Created on: Nov 29, 2022
 *      Author: PC
 */

#include "fsm_manual.h"

void fsm_modify_timer_control() {
	switch (status3) {
	case MODIFY_RED1:
		if (isTimer1Expired()) {
			setTimer1(50);
			clearAllLed();
			counter_toggle++;
			if (counter_toggle > 2) {
				counter_toggle = 0;
				toggleRed2();
			}
			toggleRed1();
		}
		//check if user want to apply new duration1 and return auto mode
		if (isButtonPressed(RETURN)) {
			clearAllLed();
			//set new duration1 for red led
			red_duration1 = time_input * 100;
			time_input = 1;
			status3 = MODIFY_YELLOW1;
		}
		//check if user want to increase time
		if (isButtonPressed(INC_TIME) || isButtonPressed1s(INC_TIME)) {
			time_input = (time_input + 1) % 100; //max value is 99
			if (time_input == 0)
				time_input = 1; //0 is invalid value
			writeMess(time_input);
		}

		//decrease time
		if (isButtonPressed(DEC_TIME) || isButtonPressed1s(DEC_TIME)) {
			time_input = (time_input - 1);
			if (time_input == 0)
				time_input = 99; //0 is invalid value
			writeMess(time_input);
		}

		//check if user want to change mode
		if (isButtonPressed(CONTROL_MODE)) {
			clearAllLed();
			time_input = 1;
			status3 = MODIFY_YELLOW1;
		}
		break;

	case MODIFY_YELLOW1:
		if (isTimer1Expired()) {
			setTimer1(50);
			clearAllLed();
			toggleYellow1();
			counter_toggle++;
			if (counter_toggle > 2) {
				counter_toggle = 0;
				toggleYellow2();
			}
		}
		//check if user want to apply new duration1 and return auto mode
		if (isButtonPressed(RETURN)) {
			clearAllLed();
			//set new duration1 for yellow led
			yellow_duration1 = time_input * 100;
			time_input = 1;
			status3 = MODIFY_GREEN1;
		}

		//check if user want to increase time
		if (isButtonPressed(INC_TIME) || isButtonPressed1s(INC_TIME)) {
			time_input = (time_input + 1) % 100; //99 is the max value
			if (time_input == 0)
				time_input = 1; //0 is invalid value
			writeMess(time_input);
		}

		//decrease time
		if (isButtonPressed(DEC_TIME) || isButtonPressed1s(DEC_TIME)) {
			time_input = (time_input - 1);
			if (time_input == 0)
				time_input = 99; //0 is invalid value
			writeMess(time_input);
		}

		//check if user want to change mode
		if (isButtonPressed(CONTROL_MODE)) {
			clearAllLed();
			time_input = 1;
			status3 = MODIFY_GREEN1;
		}
		break;

	case MODIFY_GREEN1:
		if (isTimer1Expired()) {
			setTimer1(50);
			clearAllLed();
			toggleGreen1();
			counter_toggle++;
			if (counter_toggle > 2) {
				counter_toggle = 0;
				toggleGreen2();
			}
		}
		//check if user want to apply new duration1 and return auto mode
		if (isButtonPressed(RETURN)) {
			clearAllLed();
			//set new duration1 for green led
			green_duration1 = time_input * 100;
			time_input = 1;
			status3 = MODIFY_RED2;
		}

		//check if user want to increase time
		if (isButtonPressed(INC_TIME) || isButtonPressed1s(INC_TIME)) {
			time_input = (time_input + 1) % 100; //99 is the max value
			if (time_input == 0)
				time_input = 1; //1 is invalid value
			writeMess(time_input);
		}

		//decrease time
		if (isButtonPressed(DEC_TIME) || isButtonPressed1s(DEC_TIME)) {
			time_input = (time_input - 1);
			if (time_input == 0)
				time_input = 99; //0 is invalid value
			writeMess(time_input);
		}

		//check if user want to change mode
		if (isButtonPressed(CONTROL_MODE)) {
			clearAllLed();
			time_input = 1;
			status3 = MODIFY_RED2;
		}
		break;

	case MODIFY_RED2:
		if (isTimer1Expired()) {
			setTimer1(50);
			clearAllLed();
			toggleRed2();
			counter_toggle++;
			if (counter_toggle > 2) {
				counter_toggle = 0;
				toggleRed1();
			}
		}
		//check if user want to apply new duration1 and return auto mode
		if (isButtonPressed(RETURN)) {
			clearAllLed();
			//set new duration1 for green led
			red_duration2 = time_input * 100;
			time_input = 1;
			status3 = MODIFY_YELLOW2;
		}

		//check if user want to increase time
		if (isButtonPressed(INC_TIME) || isButtonPressed1s(INC_TIME)) {
			time_input = (time_input + 1) % 100; //99 is the max value
			if (time_input == 0)
				time_input = 1; //1 is invalid value
			writeMess(time_input);
		}

		//decrease time
		if (isButtonPressed(DEC_TIME) || isButtonPressed1s(DEC_TIME)) {
			time_input = (time_input - 1);
			if (time_input == 0)
				time_input = 99; //0 is invalid value
			writeMess(time_input);
		}

		//check if user want to change mode
		if (isButtonPressed(CONTROL_MODE)) {
			clearAllLed();
			time_input = 1;
			status3 = MODIFY_YELLOW2;
		}
		break;

	case MODIFY_YELLOW2:
		if (isTimer1Expired()) {
			setTimer1(50);
			clearAllLed();
			toggleYellow2();
			counter_toggle++;
			if (counter_toggle > 2) {
				counter_toggle = 0;
				toggleYellow1();
			}
		}

		//check if user want to apply new duration1 and return auto mode
		if (isButtonPressed(RETURN)) {
			clearAllLed();
			//set new duration1 for yellow led
			yellow_duration2 = time_input * 100;
			time_input = 1;
			status3 = MODIFY_GREEN2;
		}

		//check if user want to increase time
		if (isButtonPressed(INC_TIME) || isButtonPressed1s(INC_TIME)) {
			time_input = (time_input + 1) % 100; //99 is the max value
			if (time_input == 0)
				time_input = 1; //0 is invalid value
			writeMess(time_input);
		}

		//decrease time
		if (isButtonPressed(DEC_TIME) || isButtonPressed1s(DEC_TIME)) {
			time_input = (time_input - 1);
			if (time_input == 0)
				time_input = 99; //0 is invalid value
			writeMess(time_input);
		}

		//check if user want to change mode
		if (isButtonPressed(CONTROL_MODE)) {
			clearAllLed();
			time_input = 1;
			status3 = MODIFY_GREEN2;
		}
		break;

	case MODIFY_GREEN2:
		if (isTimer1Expired()) {
			setTimer1(50);
			clearAllLed();
			toggleGreen2();
			counter_toggle++;
			if (counter_toggle > 2) {
				counter_toggle = 0;
				toggleGreen1();
			}
		}
		//check if user want to apply new duration1 and return auto mode
		if (isButtonPressed(RETURN)) {
			clearAllLed();
			//set new duration1 for green led
			green_duration2 = time_input * 100;
			time_input = 1;
			//turn on return flag for the fsm auto can change it's state
			returnFlag1 = 1;
			returnFlag2 = 1;
			status3 = WAIT;
			//set display pointer back to normal
		}

		//check if user want to increase time
		if (isButtonPressed(INC_TIME) || isButtonPressed1s(INC_TIME)) {
			time_input = (time_input + 1) % 100; //99 is the max value
			if (time_input == 0)
				time_input = 1; //1 is invalid value
			writeMess(time_input);
		}

		//decrease time
		if (isButtonPressed(DEC_TIME) || isButtonPressed1s(DEC_TIME)) {
			time_input = (time_input - 1);
			if (time_input == 0)
				time_input = 99; //0 is invalid value
			writeMess(time_input);
		}

		//check if user want to change mode
		if (isButtonPressed(CONTROL_MODE)) {
			time_input = 1;
			clearAllLed();
			returnFlag1 = 1;
			returnFlag2 = 1;
			status3 = WAIT;
		}
		break;

	case WAIT:
		//DO NOTHING
		break;

	default:
		break;
	}
}
