#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int In_out_checker(FILE* myfile);

int main()
{
	FILE* myfile;
	myfile = fopen("in_out_check.txt", "r");
	In_out_checker(myfile);
	return 0;
}

int In_out_checker(FILE* myfile)
{
	char a, b;
//	_Bool i, switcher = 1;
	int tmp = 0, n = 1;
	int* in = NULL;
	int* out = NULL;
	while ((a = fgetc(myfile)) != EOF)
	{
		switch (a)
		{
		case ':':
			tmp = atoi(a);
			tmp *= 60;
		case ' ':
			tmp += atoi(a);
			in = (int*)realloc(in, n * sizeof(int));
			in[n - 1] = tmp;
			++n;
		case '\n':
			tmp += atoi(a);
			out = (int*)realloc(out, n * sizeof(int));
			out[n - 1] = tmp;
			++n;
		default:
			b = a;
			break;
		}
	}
	for (int i = 0; i < n; ++i)
		printf("%d %d\n", in[i], out[i]);
	return 0;
}
