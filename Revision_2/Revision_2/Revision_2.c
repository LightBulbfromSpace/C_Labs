#include <stdio.h>

int main()
{
	int n = 4;
	int** array = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		array[i] = (int*)malloc(n * sizeof(int));
	}
	int j = 1, k = 1;
	for (int i = 2; i <= (2 * n); i++)
	{
		
	}

	for (int i = 0; i < n; i++) {
		free(array[i]);
	}
	free(array);
}

