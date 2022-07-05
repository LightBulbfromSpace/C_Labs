#include <stdio.h>
#include <stdlib.h>

void snake_matrix(int n, int** a) {
	int k = 0, l = 1, z = -1;
	for (int i = 0; i <= 2*n; i++) {
		while ((i - k) > z) {
			a[i-k][k] = i % 2 == 1? l : l + i - 2*k;
			l++; k++;
		}
		if (i < n - 1)
			k = 0;
		else { k = i - n + 2; z++; }
	}
}

void matrix_output(int n, int** a) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			printf("%3d ", a[i][j]);
		printf("\n");
	}
}

void delete_matrix(int n, int** a) {
	for (int i = 0; i < n; i++)
		free(a[i]);
	free(a);
}

int main()
{
	for (int n = 4; n < 7; n++) {
		int** array = (int**)malloc(n * sizeof(int*));
		for (int i = 0; i < n; i++)
			array[i] = (int*)malloc(n * sizeof(int));
		snake_matrix(n, array);
		matrix_output(n, array);
		delete_matrix(n, array);
		printf("\n");
	}
}

