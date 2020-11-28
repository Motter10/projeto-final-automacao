/*
 * utils.c
 *
 *  Created on: 28 de nov de 2020
 *      Author: sandr
 */
#include "utils.h"

void UTILS_get_Hour(char* hour)
{
	  struct tm *sTm;

	  time_t now = time (0);
	  sTm = gmtime (&now);

	  strftime (hour, 9, "%H:%M:%S", sTm);
	  return;
}
