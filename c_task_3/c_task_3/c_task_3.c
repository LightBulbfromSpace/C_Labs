#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int Counter_of_words(FILE* myfile);
void Inversion_of_text(FILE* myfile);


int main()
{
    FILE* myfile;
    myfile = fopen("BogeyBeast.txt", "r");
    printf("%d\n", Counter_of_words(myfile));
    myfile = fclose(myfile);
    myfile = fopen("BogeyBeast.txt", "r");
    Inversion_of_text(myfile);
    return 0;
}

int Counter_of_words(FILE* myfile)
{
    int words = 1;
    char b = 0, a;
    while ((a = fgetc(myfile)) != EOF)
    {
        (int)a;
        if ((a >= 'A' && a <= 'Z') || (a >= 'a' && a <= 'z'))
            if (b >= ' ' && b <= '?')
                words++;
        b = a;
    }
    return words;
}

void Inversion_of_text(FILE* myfile)
{
    char* buffer = NULL;
    char a;
    int i = 0;
    while ((a = fgetc(myfile)) != EOF)
    {
        buffer = (char*)realloc(buffer, (i + 1) * sizeof(char));
        buffer[i] = a;
        i++;
    }
    for (int j = i - 1; j >= 0; j--)
        printf("%c", buffer[j]);
    free(buffer);
}
