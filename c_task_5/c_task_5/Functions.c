#include <stdio.h>
#include <stdarg.h>
#include "Functions.h"

typedef struct {
	int x;
	int y;
} Point;

_Bool RectCheck(Point p1, Point p2, Point p3, Point p4)
{
	return (p1.x == p2.x && p3.x == p4.x && p1.y == p3.y && p2.y == p4.y
		|| p1.x == p3.x && p2.x == p4.x && p1.y == p2.y && p3.y == p4.y);
}

int StarRectsCounter(int n, Point* points)
{
	if (n < 4)
		return 0;
	int counter = 0;
	for (int i = 0; i < (n - 3); i++)
		for (int j = i + 1; j < (n - 2); j++)
			for (int k = j + 1; k < (n - 1); k++)
				for (int g = k + 1; g < n; g++)
					if (RectCheck(points[i], points[j], points[k], points[g]))
						counter++;
	return counter;
}

int Thimbles(char* str)
{
	int currently = 1;
	while (*str)
	{
		switch (*str)
		{
		case 'A':
			if (currently != 3)
				currently = 3 - currently;
			break;
		case 'B':
			if (currently != 1)
				currently = 5 - currently;
			break;
		case 'C':
			if (currently != 2)
				currently = 4 - currently;
			break;
		}
		++str;
	}
	return currently;
}