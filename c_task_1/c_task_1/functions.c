#include "functions.h"
#include <string.h>

int strcmp(char* s1, char* s2)
{
    while (*s1)
    {
        if (*s1 != *s2) {
            break;
        }
        s1++;
        s2++;
    }
    if (*(unsigned char*)s1 < *(unsigned char*)s2)
        return -1;
    return (*(unsigned char*)s1 > *(unsigned char*)s2);
}

_Bool Palindrome(char* word)
{
    int len = strlen(word);
    if (len == 1)
        return 1;
    _Bool flag = 1;
    for (int i = 0; i < (len / 2); i++)
        if (word[i] != word[len - i - 1])
            flag = 0;
    return flag;
}

char* strstr(char* str, char* substr)
{
    if (strlen(str) < strlen(substr) || strlen(str) == 0 || strlen(substr) == 0)
        return NULL;
    int count = 0;
    int j = 0;
    char* p = NULL;
      for (int i = 0; i < (strlen(str)); i++) {
        if (str[i] == substr[j]) {
            if (!count)
                p = str[i];
            ++count;
            ++j;
        }
        else {
            count = 0;
            j = 0;
        }
        if (count == strlen(substr))
            return p;
    }
    return NULL;
}
