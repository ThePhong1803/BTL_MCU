/*
 * pedestrian.c
 *
 *  Created on: Dec 6, 2022
 *      Author: ADMIN
 */

#include "pedestrian.h"

void fsm_pedestrian() {
	switch (status4) {
	case PEDESTRIAN_RUN_ALLOW:
		// Turn on led which allow pedestrian go
		HAL_GPIO_WritePin(L2_EN0_GPIO_Port, L2_EN0_Pin, RESET);
		HAL_GPIO_WritePin(L2_EN1_GPIO_Port, L2_EN1_Pin, SET);

		// Change mode when timer expired
		if (isTimer5Expired()) {
			status4 = PEDESTRIAN_OFF;
		}

		// Setup buzzer
		if (isTimer6Expired()) {
			if (timeCountdown1 <= 5) {
				__HAL_TIM_SetCompare(&htim3,TIM_CHANNEL_1,(5-timeCountdown1)*20);
				setTimer6(100);
			}
		}

		// Change mode when auto mode change
		if (status1 == AUTO_GREEN || status1 == AUTO_YELLOW) {
			status4 = PEDESTRIAN_RUN_NOT_ALLOW;
			__HAL_TIM_SetCompare(&htim3,TIM_CHANNEL_1,0);
		}

		// Refresh time if user request
		if (isButtonPressed(3)) {
			setTimer5(1000);
		}
		break;

	case PEDESTRIAN_RUN_NOT_ALLOW:
		// Turn on led which not allow pedestrian go
		HAL_GPIO_WritePin(L2_EN0_GPIO_Port, L2_EN0_Pin, SET);
		HAL_GPIO_WritePin(L2_EN1_GPIO_Port, L2_EN1_Pin, RESET);

		// Change mode when timer expired
		if (isTimer5Expired()) {
			status4 = PEDESTRIAN_OFF;
			__HAL_TIM_SetCompare(&htim3,TIM_CHANNEL_1,0);
		}

		// Change mode when auto mode change
		if (status1 == AUTO_RED) {
			status4 = PEDESTRIAN_RUN_ALLOW;
			setTimer6(100);
		}

		// Refresh time when user request
		if (isButtonPressed(3)) {
			setTimer5(1000);
		}
		break;

	case PEDESTRIAN_OFF:
		// Turn off led and buzzer
		HAL_GPIO_WritePin(L2_EN0_GPIO_Port, L2_EN0_Pin, RESET);
		HAL_GPIO_WritePin(L2_EN1_GPIO_Port, L2_EN1_Pin, RESET);
		__HAL_TIM_SetCompare(&htim3,TIM_CHANNEL_1,0);
		// Change mode when user request corresponding with auto mode
		if (status1 != WAIT) {
			if(status1 == AUTO_RED && isButtonPressed(3)){
				status4 = PEDESTRIAN_RUN_ALLOW;
				setTimer5(1000);
				setTimer6(1);
			}
			else if((status1 == AUTO_GREEN || status1 == AUTO_YELLOW) && isButtonPressed(3)) {
				status4 = PEDESTRIAN_RUN_NOT_ALLOW;
				setTimer5(1000);
			}
		}
		break;
	default:
		// Do nothing
		break;
	}
}
