#include <stdio.h>
#include "Test.h"
#include "Calc.h"

void Check(int want, char* exp)
{
	int got = Calc(exp);
	if (got != want) { printf("test for %s was failed\n", exp); }
	if (got == want) { printf("test for %s was passed\n", exp); }
}

void CalcTest()
{
	int n = 0;
	//"2+x=5"
	int want = 3;
	Check(want, "2+x=5");

	//"x+2=5"
	want = 3;
	Check(want, "x+2=5");

	//"2+55=x"
	want = 57;
	Check(want, "2+55=x");

	//"x=923+34"
	want = 957;
	Check(want, "x=923+34");

	//"12=x+2"
	want = 10;
	Check(want, "12=x+2");

	//"15=2+x"
	want = 13;
	Check(want, "15=2+x");

	//"x-5=2"
	want = 7;
	Check(want, "x-5=2");

	//"5-x=20"
	want = -15;
	Check(want, "5-x=20");

	//"56-2=x"
	want = 54;
	Check(want, "56-2=x");

	//"x=5-20"
	want = -15;
	Check(want, "x=5-20");

	//"5=x-20"
	want = 25;
	Check(want, "5=x-20");

	//"30=70-x"
	want = 40;
	Check(want, "30=70-x");

	//"x*5=10"
	want = 2;
	Check(want, "x*5=10");

	//"5*x=10"
	want = 2;
	Check(want, "5*x=10");

	//"9*9=x"
	want = 81;
	Check(want, "9*9=x");

	//"x=5*10"
	want = 50;
	Check(want, "x=5*10");

	//"10=x*10"
	want = 1;
	Check(want, "10=x*10");

	//"9=9*x"
	want = 1;
	Check(want, "9=9*x");

	//"x=10/3"
	want = 3;
	Check(want, "x=10/3");

	//"3=x/2"
	want = 6;
	Check(want, "3=x/2");

	//"33=99/x"
	want = 3;
	Check(want, "33=99/x");

	//"x/2=5"
	want = 10;
	Check(want, "x/2=5");

	//"10/x=5"
	want = 2;
	Check(want, "10/x=5");

	//"10/2=x"
	want = 5;
	Check(want, "10/2=x");

	//"x=10%3"
	want = 1;
	Check(want, "x=10%3");

	//"1=3%x"
	want = 2;
	Check(want, "1=3%x");

	//"5%x=0"
	want = 5;
	Check(want, "5%x=0");

	//"10%2=x"
	want = 0;
	Check(want, "10%2=x");

}
