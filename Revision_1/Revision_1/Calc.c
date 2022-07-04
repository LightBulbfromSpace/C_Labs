#include "Calc.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int EasiestCalc(char* exp) { //работает только с однозначными числами в выражении
	if (exp[3] == '=') {
		if (exp[4] == 'x') { return Subcalc(exp[0], exp[1], exp[2]); }
		if (exp[2] == 'x') { return Subcalc(exp[0], exp[1], exp[4]); }
		if (exp[0] == 'x') { return Subcalc(exp[4], SymbChange(exp[1]), exp[2]); }
	}
	if (exp[1] == '=') {
		if (exp[0] == 'x') { return Subcalc(exp[2], exp[3], exp[4]); }
		if (exp[2] == 'x') { return Subcalc(exp[0], SymbChange(exp[3]), exp[4]); }
		if (exp[4] == 'x') { return Subcalc(exp[2], exp[3], exp[0]); }
	}
	return 0;
}

int Subcalc(char a, char symb, char b) {
	if (symb == '+') { return (a - 48) + (b - 48); }
	if (symb == '-') { return (a - 48) - (b - 48); }
	if (symb == '*') { return (a - 48) * (b - 48); }
	if (symb == '%') { return (a - 48) % (b - 48); }
	return (a - 48) / (b - 48);
}

char SymbChange(char symb) {
	if (symb == '*' || symb == '/') { return 89 - symb; }
	return 88 - symb;
}

int Calc(char* exp) 
{
	int indexX, indexE, indexO;
	_Bool SymCh = 0, NumCh = 0, flag = 0;
	char operator;
	char* num1 = (char*)malloc(strlen(exp) - 2);
	char* num2 = (char*)malloc(strlen(exp) - 2);
	for (int i = 0; i < strlen(exp); i++) {
		if (exp[i] == 'x') { indexX = i; }
		if (exp[i] == '=') { indexE = i; }
		if (exp[i] < 48 ) { indexO = i; }
	}
	if (indexX < indexO && indexO < indexE) { //#1
		memcpy(num1, &exp[2], indexE - indexO);
		num1[indexE - 2] = '\0';
		memcpy(num2, &exp[indexE + 1], strlen(exp) - indexE - 1);
		num2[strlen(exp) - indexE - 1] = '\0';
		SymCh = 1; NumCh = 1;
	}
	if (indexX < indexE && indexE < indexO) { //#2
		memcpy(num1, &exp[2], indexO - indexE);
		num1[indexO - indexE - 1] = '\0';
		memcpy(num2, &exp[indexO + 1], strlen(exp) - indexO - 1);
		num2[strlen(exp) - indexO - 1] = '\0';
	}
	if (indexO < indexX && indexX < indexE) { //#3
		memcpy(num1, &exp[0], indexO);
		num1[indexO] = '\0';
		memcpy(num2, &exp[indexE + 1], strlen(exp) - indexE - 1);
		num2[strlen(exp) - indexE - 1] = '\0';
		if (exp[indexO] == '+' || exp[indexO] == '*') { SymCh = 1; NumCh = 1; }
		if (exp[indexO] == '%') { flag = 1;  }
	}
	if (indexO < indexE && indexE < indexX) { //#4
		memcpy(num1, &exp[0], indexO);
		num1[indexO] = '\0';
		memcpy(num2, &exp[indexO + 1], strlen(exp) - indexE);
		num2[strlen(exp) - indexO - 3] = '\0';
	}
	if (indexE < indexX && indexX < indexO) { //#5
		memcpy(num1, &exp[0], indexE);
		num1[indexE] = '\0';
		memcpy(num2, &exp[indexO + 1], strlen(exp) - indexO - 1);
		num2[strlen(exp) - indexO - 1] = '\0';
		SymCh = 1;
	}
	if (indexE < indexO && indexO < indexX) { //#6
		memcpy(num2, &exp[0], indexE);
		num2[indexE] = '\0';
		memcpy(num1, &exp[indexE + 1], indexO - indexE - 1);
		num1[indexO - indexE - 1] = '\0';
		if (exp[indexO] == '+' || exp[indexO] == '*') { SymCh = 1; NumCh = 1; }
		if (exp[indexO] == '%') { flag = 1; }
	}
	operator = SymCh ? SymbChange(exp[indexO]) : exp[indexO];
	return NewSubcalc(num1, operator, num2, NumCh, flag);
}

int NewSubcalc(char* num1, char symb, char* num2, _Bool NumCh, _Bool flag) {
	int n1, n2;
	if (NumCh && (symb == '-' || symb == '/')) { n2 = atoi(num1), n1 = atoi(num2); }
	else { n1 = atoi(num1), n2 = atoi(num2); }
	free(num1);
	free(num2);
	if (symb == '+') { return n1 + n2; }
	else if (symb == '-' || flag) { return n1 - n2; }
	else if (symb == '*') { return n1 * n2; }
	else if (symb == '%') { return n1 % n2; }
	return n1 / n2;
}
