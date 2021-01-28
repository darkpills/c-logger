/*
Copyright (c) 2021 - darkpills

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/


// Imported from repository https://github.com/darkpills/c-logger

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>


int doLog(char * logFilename, char * id, char *message) {
	FILE *fptr;
	time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
	timeinfo=localtime(&rawtime);
	fptr = fopen(logFilename,"a+");
	if (fptr == NULL)
	{
		printf("\n\nThere was a problem opening the log file!\n\n");
		sleep(2);
		return 1;
	}
	
	fseek(fptr, 0L, SEEK_END);
	fprintf(fptr,"%s: %s at %s", id,  message, asctime(timeinfo));

	if (fclose(fptr) != 0)
	{
		printf("Error closing log file!");
		return 1;
	}

	return 0;
}