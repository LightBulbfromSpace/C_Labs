#include <stdio.h>
#include "test.h"
#include "functions.h"

void Check(char* exp, int step, int want)
{
	int got = hopcost(exp, step);
	if (got != want)
		printf("for \"%s\" wanted %d but got %d\n", exp, want, got);
	else
		printf("test for \"%s\" was passed, got %d\n", exp, got);
}

void hopcostTest()
{
	//"ABCADBACB"
	int want = 1;
	Check("ABCADBACB", 3, want);

	//"ABCDDBBCABBACCADEA", step = 4
	want = 2;
	Check("ABCDEIJKL", 4, want);

	//"ABABBCACBC", step = 2
	want = 2;
	Check("ABABBCACBC", 2, want);

	//"ABABBCACBC", step = 9
	want = 1;
	Check("ABABBCACBC", 9, want);

	//"ABABBCACBA", step = 9
	want = 0;
	Check("ABABBCACBA", 9, want);

	//"ABCADBACCA"
	want = 0;
	Check("ABCADBACCA", 3, want);

	//"ABCDDBBCABBACCADEA", step = 3
	want = 3;
	Check("ABCDDBBCABBACCADEA", 3, want);

	//"ABCDDBBCCADEACBABCABBACCADEA", step = 3
	want = 3;
	Check("ABCDDBBCCADEACBABCABBACCADEA", 3, want);
}