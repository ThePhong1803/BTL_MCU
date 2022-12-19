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
		HAL_GPIO_WritePin(L2_EN0_GPIO_Port, L2_EN0_Pin, RESET);
		HAL_GPIO_WritePin(L2_EN1_GPIO_Port, L2_EN1_Pin, SET);
		if (isTimer5Expired()) {
			status4 = PEDESTRIAN_OFF;
		}
		if (isTimer6Expired()) {
			if (timeCountdown1 <= 5) {
				__HAL_TIM_SetCompare(&htim3,TIM_CHANNEL_1,(5-timeCountdown1)*20);
				setTimer6(100);
			}
		}

		if (status1 == AUTO_GREEN || status1 == AUTO_YELLOW) {
			status4 = PEDESTRIAN_RUN_NOT_ALLOW;
			__HAL_TIM_SetCompare(&htim3,TIM_CHANNEL_1,0);
		}
		if (isButtonPressed(3)) {
			setTimer5(1000);
		}
		break;
	case PEDESTRIAN_RUN_NOT_ALLOW:
		HAL_GPIO_WritePin(L2_EN0_GPIO_Port, L2_EN0_Pin, SET);
		HAL_GPIO_WritePin(L2_EN1_GPIO_Port, L2_EN1_Pin, RESET);
		if (isTimer5Expired()) {
			status4 = PEDESTRIAN_OFF;
			__HAL_TIM_SetCompare(&htim3,TIM_CHANNEL_1,0);
		}
		if (status1 == AUTO_RED) {
			status4 = PEDESTRIAN_RUN_ALLOW;
			setTimer6(100);
		}
		if (isButtonPressed(3)) {
			setTimer5(1000);
		}
		break;
	case PEDESTRIAN_OFF:
		HAL_GPIO_WritePin(L2_EN0_GPIO_Port, L2_EN0_Pin, RESET);
		HAL_GPIO_WritePin(L2_EN1_GPIO_Port, L2_EN1_Pin, RESET);
		__HAL_TIM_SetCompare(&htim3,TIM_CHANNEL_1,0);
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
		break;
	}
}
