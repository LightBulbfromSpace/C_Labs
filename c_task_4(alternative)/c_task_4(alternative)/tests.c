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

void Check(int n, int want)
{
	int got = SimpleKettlebells(n, 0);
	if (got != want)
		printf(" got %d but want %d\n", got, want);
	else
		printf(" test for %d was passed\n", n);
}

void SimpleKettlebellsTest()
{
	//n = 6
	int want = 3;
	Check(6, want);

	//n = 7
	want = 3;
	Check(7, want);

	//n = 8
	want = 4;
	Check(8, want);

	//n = 9
	want = 4;
	Check(9, want);

	//n = 10
	want = 5;
	Check(10, want);

	//n = 11
	want = 5;
	Check(11, want);

	//n = 13
	want = 11;
	Check(23, want);
}
