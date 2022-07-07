#include "functions.h"
#include <string.h>

int hopcost_recursion(char* str, int step, int current_letter, int count, int help_counter, int help_index, char last_cur_letter)
{
	if (strlen(str) - current_letter <= step) {
		if (str[current_letter] != str[strlen(str) - 1] || last_cur_letter != str[strlen(str) - 1])
			count++;
		return count;
	}
	int index = 0;
	_Bool flag = 0;
	for (int i = current_letter + 1; i <= current_letter + step; i++)
		if (str[current_letter] == str[i]) {
			flag = 1;
			index = i;
		}
	help_index = help_index < index ? index : help_index;
	if (flag && help_counter == 0)
		return hopcost_recursion(str, step, index, count, 0, 0, str[index]);
	else
	{
		help_counter++;
		if (help_counter > step) {
			count++;
			help_index = help_index == 0 ? current_letter + 1 : help_index;
			return hopcost_recursion(str, step, help_index, count, 0, 0, str[help_index]);
		}
		return hopcost_recursion(str, step, current_letter + 1, count, help_counter, help_index, last_cur_letter);
	}
}

int hopcost(char* str, int step)
{
	return hopcost_recursion(str, step, 0, 0, 0, 0, '\0');
}