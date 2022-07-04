#include <malloc.h>
#include <stdio.h>
#include "Tests.h"
#include "Functions.h"

typedef struct {
	int x;
	int y;
} Point;

void ThimblesTest()
{
	//"CBABCACCC"
	printf("\nThimblesTest\n");
	int got = Thimbles("CBABCACCC");
	int want = 1;
	if (got != want)
		puts("test failed");
	else
		puts("test was passed successfully");
}

void SRCheck(Point* points, int want, int n)
{
	int got = StarRectsCounter(n, points);
	if (got != want)
		printf("want %d but got %d\n", want, got);
	else
		printf("test for %d points was passed succefully\n", n);
}

void StarRectsCounterTest()
{
	printf("\nStarRectsCounterTest\n");
	Point points1[] = {0,0, 0,1, 1,0, 1,1, 2,0, 2,1, 3,0};
	int want = 3;
	SRCheck(&points1, want, 7);

	Point points2[] = { 0,0, 0,1, 1,0, 1,1, 2,0, 2,1, 3,0, 3,1};
	want = 6;
	SRCheck(&points2, want, 8);
}
