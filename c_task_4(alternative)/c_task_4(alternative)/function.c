#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "function.h"

int In_out_Museum(FILE* myfile)
{
	char str[13];
	int n = 0;
	int* in = (int*)malloc(40);
	int* out = (int*)malloc(40);
	while (fgets(str, 13, myfile) != NULL)
	{
			in[n] = ((str[0] - 48) * 10 + str[1] - 48) * 60 + (str[3] - 48) * 10 + str[4] - 48;
			out[n] = ((str[6] - 48) * 10 + str[7] - 48) * 60 + (str[9] - 48) * 10 + str[10] - 48;
		++n;
		if ((n % 10 == 0) && n != 0) // not used for in_out_check1.txt
		{
			in = realloc(in, sizeof(in) + 40);
			out = realloc(out, sizeof(out) + 40);
		}
	}
	int count = 1, max = 1;
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = i + 1; j < n; ++j)
			count = (out[i] > in[j]) ? count + 1 : count;
		max = (count > max) ? count : max;
		count = 1;
	}
	free(in);
	free(out);
	return max;
}

_Bool SimpleNumber(int num) {
	for (int i = 2; i <= sqrt(num); i++)
		if (num % i == 0)
			return 0;
	return 1;
}

int SimpleKettlebells(int n, int count)
{
	int k = n, z = 0;
	do k++; while (!SimpleNumber(k));
	z = k - n;
	for (int i = 0; i < (n - z + 1)/2; i++) {
		printf("(%d, %d)", i + z, n - i);
		count++;
	}
	if (z > 1)
		return SimpleKettlebells(z - 1, count);
	return count;
}

