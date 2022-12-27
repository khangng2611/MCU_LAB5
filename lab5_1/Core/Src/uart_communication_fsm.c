/*
 * uart_communication_fsm.c
 *
 *  Created on: Dec 14, 2022
 *      Author: HP
 */
#include "uart_communication_fsm.h"
ADC_HandleTypeDef hadc1;
UART_HandleTypeDef huart2;
uint32_t ADC_value = 0;
char str[50];
void uart_communiation_fsm() {
	switch (status1) {
	case RECEIVE:
		if (command_flag == 1 && (command_data == 1)) {
			//get ADC value
			ADC_value = HAL_ADC_GetValue(&hadc1);
			//move to status1 = TRANSMIT
			status1 = TRANSMIT;
		}
		command_flag = 0;
		break;
	case TRANSMIT:
		//send data to console
	  	HAL_UART_Transmit(&huart2, (void *)str , sprintf(str, "!ADC=%d#\r\n", ADC_value), 1000) ;
	  	status1 = WAIT_OK;
	  	setTimer1(3000);
		break;
	case WAIT_OK:
		if (timer1_flag == 1) {
			//time out 3s
			status1 = TRANSMIT;
		}
		if (command_flag == 1) {
			status1 = RECEIVE;
		}
		break;
	default:
		break;
	}
}

