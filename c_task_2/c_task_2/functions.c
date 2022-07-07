#include "functions.h"

_Bool parenthesesCheck(const char* str)
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
                    return 0;
        }
        else if (*str == 41)
        {
            --count;
            str--;
            if (*str != 41)
                if (count < 0 || !(*str >= 48 && *str <= 57 || *str >= 65 && *str <= 90
                    || *str >= 97 && *str <= 122))
                    return 0;
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
            num = num * 10 + (*str - 48);
        else
            return -1;
        ++zeros;
        ++str;
    }
    return num;
}