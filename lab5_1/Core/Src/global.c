/*
 * global.c
 *
 *  Created on: Dec 14, 2022
 *      Author: HP
 */


#include "global.h"
uint8_t temp;
uint8_t buffer [ MAX_BUFFER_SIZE ];
uint8_t  index_buffer = 0;
uint8_t buffer_flag = 0;
int command_flag = 0;
int count_rst = 0;
int count_ok = 0;
int command_data = 0;;
int status = 0;
int status1 = 0;
