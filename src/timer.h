/*
  Name:         Zeta
  Description:  Experimental chess engine written in OpenCL.
  Author:       Srdja Matovic <s.matovic@app26.de>
  Created at:   2011-01-15
  Updated at:   2016-09
  License:      GPL >= v2

  Copyright (C) 2011-2016 Srdja Matovic

  Zeta is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 2 of the License, or
  (at your option) any later version.

  Zeta is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
*/

#ifndef TIMER_H_INCLUDED
#define TIMER_H_INCLUDED

#include <windows.h> 
#include <string.h>     // for string compare
#include <time.h>       // for time measurent
//#include <sys/time.h>   // for gettimeofday

double get_time(void);
void get_date_string(char *string);
void fprintdate(FILE *file);

#endif // TIMER_H_INCLUDED

