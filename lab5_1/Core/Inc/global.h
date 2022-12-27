/*
 * global.h
 *
 *  Created on: Dec 14, 2022
 *      Author: HP
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_
#include"stdint.h"
//#include"main.h"
//#include "timer.h"

#define MAX_BUFFER_SIZE 30

#define RECEIVE 10
#define TRANSMIT 11
#define WAIT_OK 12

#define INIT 19
#define START 20
#define R 21
#define RS 22
#define RST 23
#define O 24
#define OK 25
#define END_RST 26
#define END_OK 27


extern uint8_t temp;
extern uint8_t buffer [ MAX_BUFFER_SIZE ];
extern uint8_t index_buffer;
extern uint8_t buffer_flag;
extern int command_flag;
extern int command_data;

extern int status;
extern int status1;


#endif /* INC_GLOBAL_H_ */
