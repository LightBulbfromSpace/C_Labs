#include "other.h"
#include "functions.h"
#include <stdio.h>

void strcmpCheck(char* s1, char* s2, int want)
{
    int got = strcmp(s1, s2);
    if (got != want)
        printf("test for \"%s\" and \"%s\" was failed\n", s1, s2);
    else
        printf("test for \"%s\" and \"%s\" was passed\n", s1, s2);
}

void Test_for_strcmp()
{
    printf("Test_for_strcmp\n");
    int want = 0;
    strcmpCheck("abc", "abc", want);

    want = -1;
    strcmpCheck("ab", "abc", want);

    want = -1;
    strcmpCheck("", "abc", want);

    want = 1;
    strcmpCheck("ad", "abc", want);
}

void PalindromeCheck(char* s1, _Bool want)
{
    int got = Palindrome(s1);
    if (got != want)
        printf("test for \"%s\" was failed\n", s1);
    else
        printf("test for \"%s\" was passed\n", s1);
}

void TestPalindrome()
{
    printf("\nTestPalindrome\n");
    _Bool want = 1;
    PalindromeCheck("ABBBBA", want);

    want = 1;
    PalindromeCheck("ABA", want);

    want = 0;
    PalindromeCheck("ADBC", want);

    want = 1;
    PalindromeCheck("A", want);
}

void PointersCheck(char* str, char* substr, char* want)
{
    char* got = strstr(str, substr);
    if (got == want)
        printf("test for \"%s\" and \"%s\" was passed\n", str, substr);
    else
        printf("wanted %p but got %p\n", want, got);
}

void Test_for_strstr()
{
    printf("\nTest_for_strstr\n");
    char* str = "ABABABA";
    char* substr = "BA";
    char* want = str[1];
    PointersCheck(str, substr, want);

    str = "ABAB";
    substr = "BA";
    want = str[1];
    PointersCheck(str, substr, want);

    str = "ABGHK";
    substr = "GH";
    want = str[2];
    PointersCheck(str, substr, want);

    str = "ABAB";
    substr = "";
    want = NULL;
    PointersCheck(str, substr, want);
}