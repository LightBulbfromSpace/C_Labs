#include <stdio.h>
#include <stdbool.h>

bool parenthesesCheck(const char* str); // 1st task
int atoi(char* str); // 2nd task



void parenthesesCheckTest();
void atoiTest();

bool check_for_parenthesesCheck(const char* tobj, bool want, int* count);
bool check_for_atoi(const char* tobj, int want, int* count);


int main()
{
    parenthesesCheckTest();
    atoiTest();

    return 0;
}

bool parenthesesCheck(const char* str)
{
    int count = 0;
    
    while (*str)
    {
        if (*str == 40)
        {
            ++count;
            str++;
            if (*str != 45 && *str != 40)
                if (!(*str >= 48 && *str <= 57 || *str >= 65 && *str <= 90
                    || *str >= 97 && *str <= 122))
                    return false;
        }           
        else if (*str == 41)
        {
            --count;
            str--;
            if (*str != 41)
                if (count < 0 || !(*str >= 48 && *str <= 57 || *str >= 65 && *str <= 90
                    || *str >= 97 && *str <= 122))
                    return false;
            str += 2;
        }
        else
            str++;
    }
    return (!count);   
}

int atoi(char* str)
{
    int zeros = 0;
    int num = 0;
    while (*str)
    {
        
        if (*str >= 48 && *str <= 57)
            num =  num * 10 + (*str - 48);
        else
            return -1;
        ++zeros;
        ++str;
    }
    return num;
}



bool check_for_parenthesesCheck(const char* tobj, bool want, int* count) {
    ++(*count);
    bool got = parenthesesCheck(tobj);
    if (got == want)
        printf("test %d succeeded\n", *count);
    else
        printf("test %d failed\n", *count);
    return (got != want);
}

bool check_for_atoi(char* tobj, int want, int* count)
{
    ++(*count);
    int got = atoi(tobj);
    if (got == want)
        printf("test %d succeeded\n", *count);
    else
        printf("test %d failed\n", *count);
    return (got != want);
}

void parenthesesCheckTest()
{
    bool want;
    int num_of_test = 0;
    int score_count = 0;

    //test 1 for "2+3*(a-b)"
    want = true;
    score_count += check_for_parenthesesCheck("2+3*(a-b)", want, &num_of_test);

    //test 2 for "((3+2)"
    want = false;
    score_count += check_for_parenthesesCheck("((3+2)", want, &num_of_test);

    //test 3 for ")(3+2)"
    want = false;
    score_count += check_for_parenthesesCheck(")(3+2)", want, &num_of_test);

    //test 4 for "((c+8)*10-4)"
    want = true;
    score_count += check_for_parenthesesCheck("((a+8)*10-4)", want, &num_of_test);

    //test 5 for "x*(2+2))"
    want = false;
    score_count += check_for_parenthesesCheck("x*(2+2))", want, &num_of_test);

    //test 6 for "2+)a-b)"
    want = false;
    score_count += check_for_parenthesesCheck("2+)a-b)", want, &num_of_test);

    //test 7 for "2(+)a-b"
    want = false;
    score_count += check_for_parenthesesCheck("2(+)a-b", want, &num_of_test);

    //test 8 for "2+)a-b("
    want = false;
    score_count += check_for_parenthesesCheck("2+)a-b(", want, &num_of_test);

    //test 9 for "2+a(-b)c"
    want = true;
    score_count += check_for_parenthesesCheck("2+a(-b)", want, &num_of_test);


    if (score_count == 0)
        puts("all tests are succeded");
    puts("\n");
}

void atoiTest()
{
    int want;
    int num_of_test = 0;
    int score_count = 0;

    //test 1 for "555"
    want = 555;
    score_count += check_for_atoi("555", want, &num_of_test);

    //test 2 for "0n0"
    want = -1;
    score_count += check_for_atoi("0n0", want, &num_of_test);

    //test 3 for "1523"
    want = 1523;
    score_count += check_for_atoi("1523", want, &num_of_test);

    if (score_count == 0)
        puts("all tests are succeded");
}
