#pragma once

int hopcost(char* str, int step);
int hopcost_recursion(char* str, int step, int current_letter, int count,
	int help_counter, int help_index, char last_cur_letter);
