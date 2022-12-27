/*
 * timer.h
 *
 *  Created on: Dec 26, 2022
 *      Author: HP
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

#include "main.h"

extern int timer1_flag;
extern int timer1_counter;
extern int timer2_flag;
extern int timer2_counter;
extern int tick;

void setTimer1(int duration);
void setTimer2(int duration);

void timerRun();

void HAL_TIM_PeriodElapsedCallback (TIM_HandleTypeDef* htim);

#endif /* INC_TIMER_H_ */
