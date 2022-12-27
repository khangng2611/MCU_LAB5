/*
 * command_parser_fsm.c
 *
 *  Created on: Dec 14, 2022
 *      Author: HP
 */
#include "command_parser_fsm.h"
void command_parser_fsm() {
	switch (status) {
		case INIT:
			if (temp == '!')
				status = START;
			break;
		case START:
			if (temp == 'R')
				status = R;
			else if (temp == 'O')
				status = O;
			else status = INIT;
			break;
		case R:
			if (temp == 'S')
				status = RS;
			else status = INIT;
			break;
		case RS:
			if (temp == 'T')
				status = RST;
			else status = INIT;
			break;
		case RST:
			if (temp == '#')
				status = END_RST;
			else status = INIT;
			break;
		case O:
			if (temp == 'K')
				status = OK;
			else status = INIT;
			break;
		case OK:
			if (temp == '#')
				status = END_OK;
			else status = INIT;
			break;
		case END_RST:
			command_flag = 1;
			command_data = 1;
			status = INIT;
			break;
		case END_OK:
			command_flag = 1;
			command_data = 0;
			status = INIT;
			break;
		default:
			break;
	}
}
