#include <stdio.h>
#include <array>

int hopcost(char* str, int k);


int main()
{
	hopcost("qwe", 2);

	return 0;
}

int hopcost(char* str, int k)
{
	int n = 1;
	struct quantity_and_letter
	{
		char letter;
		int frecuency;
	};

	struct quantity_and_letter *array = (struct quantity_and_letter*)malloc(26 * sizeof(struct quantity_and_letter));
	array[0].letter = 'A';
	array[0].frecuency = 0;

	printf("%c %d", array[0].letter, array[0].frecuency);

	/*while (str)
	{
		flag 
//		for (int i = 0; i < k; i++)
		for (int i = 0; i < sizeof(array); i++)
			if (array[i].letter == str)
				_
		++str;
	}*/
	return 0;
}
