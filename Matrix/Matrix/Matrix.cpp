#include <stdlib.h>
#include <iostream>

void rows_by_snake(int n, int m, int** a) {
	int i, j, k = 0;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++) {
			a[i][j] = (i % 2 ? (i + 1) * m - j - 1 : k);
			k++;
		}
}

void cols_by_snake(int n, int m, int** a) {
	int i, j, k = 0;
	for (j = 0; j < m; j++)
		for (i = 0; i < n; i++) {
			a[i][j] = (j % 2 ? (j + 1) * n - i - 1 : k);
			k++;
		}
}

void output_matrix(int n, int m, int** a) {
	int i, j;
	for (i = 0; i < n; i++) {
		std::cout << std::endl;
		for (j = 0; j < m; j++) std::cout << a[i][j] << " ";
	}
}

int main() {
	const int n = 4, m = 6;
	int** a, i;
	a = new int* [n];
	for (i = 0; i < n; i++) a[i] = new int[m];
	rows_by_snake(n, m, a);
	output_matrix(n, m, a);
	cols_by_snake(n, m, a);
	output_matrix(n, m, a);
	return 0;
}