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
#include <windows.h> 
#include <stdio.h>      // for file IO
#include <string.h>     // for string comparing functions
#include <time.h>       // for time measurement
//#include <sys/time.h>   // for gettimeofday
int gettimeofday(struct timeval* p, void* tz) {
    ULARGE_INTEGER ul; // As specified on MSDN.
    FILETIME ft;

    // Returns a 64-bit value representing the number of
    // 100-nanosecond intervals since January 1, 1601 (UTC).
    GetSystemTimeAsFileTime(&ft);

    // Fill ULARGE_INTEGER low and high parts.
    ul.LowPart = ft.dwLowDateTime;
    ul.HighPart = ft.dwHighDateTime;
    // Convert to microseconds.
    ul.QuadPart /= 10ULL;
    // Remove Windows to UNIX Epoch delta.
    ul.QuadPart -= 11644473600000000ULL;
    // Modulo to retrieve the microseconds.
    p->tv_usec = (long)(ul.QuadPart % 1000000LL);
    // Divide to retrieve the seconds.
    p->tv_sec = (long)(ul.QuadPart / 1000000LL);

    return 0;
}

// get time in milli seconds
double get_time(void) 
{
  struct timeval t;
  gettimeofday (&t, NULL);
  return t.tv_sec*1000 + t.tv_usec/1000;
}
void get_date_string(char *string)
{
  time_t t;
  struct tm *local;
  char *ptr;
  char tempstring[256];

  t = time(NULL);
  local = localtime (&t);
  strftime(tempstring, sizeof(tempstring), "%Y-%m-%d %H:%M:%S", local);

  if ((ptr = strchr (tempstring, '\n')) != NULL)
    *ptr = '\0';

  memcpy (string, tempstring, sizeof(char)*256);
}
void fprintdate(FILE *file)
{
  char timestring[256];
  get_date_string (timestring);
  fprintf(file, "[%s] ", timestring);
}

