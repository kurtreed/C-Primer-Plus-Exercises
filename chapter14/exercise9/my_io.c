//
// Created by Kurt on 7/28/2018.
//
//
// Created by Kurt on 7/27/2018.
//
#include <stdio.h>
#include "my_io.h"

void eatline(void)
{
    // Clears input buffer

    while (getchar() != '\n')
        continue;
}

char * my_gets(char *string, int n)
{
    // wrapper for fgets that replaces first newline with null
    // Returns pointer to the string copied into memory

    char *return_value = fgets(string, n, stdin);

    while (*string != '\0')
    {
        if (*string == '\n')
        {
            *string = '\0';
            break;
        }

        string++;
    }

    return return_value;
}
