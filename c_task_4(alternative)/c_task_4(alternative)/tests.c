#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "tests.h"
#include "function.h"

void MuseumChecker(FILE* myfile, int want)
{
	int got = In_out_Museum(myfile);
	if (got != want)
		printf("got %d but want %d\n", got, want);
	else
		printf("test was passed\n");
	fclose(myfile);
}

void In_out_MuseumTest()
{
	FILE* myfile;
	myfile = fopen("in_out_check1.txt", "r");
	int want = 4;
	MuseumChecker(myfile, want);

	myfile = fopen("in_out_check2.txt", "r");
	want = 6;
	MuseumChecker(myfile, want);
}
