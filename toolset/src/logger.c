/*
 * logger.c
 *
 *  Created on: Jul 10, 2015
 *      Author: netboy
 */
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

#include "../headers/logger.h"

void writelog(char * msg){
	time_t rawtime;
    char buffer[DATETIMESIZE];
	struct tm * timeinfo;

	time ( &rawtime );
	timeinfo = localtime ( &rawtime );

	strftime(buffer, DATETIMESIZE, "%Y-%m-%d %H:%M:%S", timeinfo);
	char * combinedMsg = malloc(DATETIMESIZE + strlen(msg)+2);
	strcpy (combinedMsg, buffer);
	char * comma=",";
	strcat(combinedMsg,comma);
	strcat(combinedMsg,msg);
	printf(combinedMsg);

}

