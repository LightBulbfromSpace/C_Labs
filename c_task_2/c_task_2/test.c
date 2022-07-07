#include "test.h"
#include <stdbool.h>
#include <stdio.h>

bool check_for_parenthesesCheck(const char* tobj, bool want, int* count) {
    ++(*count);
    bool got = parenthesesCheck(tobj);
    if (got == want)
        printf("test %d for \"%s\" succeeded (%d)\n", *count, tobj, got);
    else
        printf("test %d for \"%s\" failed (%d)\n", *count, tobj, got);
    return (got != want);
}

void parenthesesCheckTest()
{
    bool want;
    int num_of_test = 0;
    int score_count = 0;
    
    printf("parenthesesCheckTests\n");

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

bool check_for_atoi(char* tobj, int want, int* count)
{
    ++(*count);
    int got = atoi(tobj);
    if (got == want)
        printf("test %d for \"%s\" succeeded (%d)\n", *count, tobj, got);
    else
        printf("test %d for \"%s\" failed (%d)\n", *count, tobj, got);
    return (got != want);
}

void atoiTest()
{
    int want;
    int num_of_test = 0;
    int score_count = 0;
    
    printf("atoiTests\n");

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
