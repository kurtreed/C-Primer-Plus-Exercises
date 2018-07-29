// C Primer Plus
// Chapter 14 Exercise 3:

// Revise the book-listing program in Listing 14.2 so that it prints the book
// descriptions in the order entered, then alphabetized by title, and then in
// order of increased value.

// Created by Kurt Reed

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100 /* maximum number of books */

struct book { /* set up book template */
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

char * my_gets(char *string, int n);
void title_sort(struct book ** bp, int count);
void value_sort(struct book ** bp, int count);

int main(void)
{
    struct book *library[MAXBKS]; /* array of pointers to book structures */
    int count = 0;
    int index;
    char temp[MAXTITL];
    printf("Does z come first?: %d\n", strcmp("Zebra", "alpha"));
    printf("Please enter the book title.\n");
    printf("Press [enter] at the start of a line to stop.\n");
    while (count < MAXBKS && my_gets(temp, MAXTITL) != NULL
           && temp[0] != '\0')
    {
        library[count] = (struct book *) malloc(sizeof(struct book));
        strncpy(library[count]->title, temp, MAXTITL);

        printf("Now enter the author.\n");
        gets(library[count]->author);
        printf("Now enter the value.\n");
        scanf("%f", &library[count++]->value);
        while (getchar() != '\n')
            continue; /* clear input line */
        if (count < MAXBKS)
            printf("Enter the next title.\n");
    }
    if (count > 0)
    {
        printf("Here is the list of your books in original order:\n");
        for (index = 0; index < count; index++)
            printf("%s by %s: $%.2f\n", library[index]->title,
                   library[index]->author, library[index]->value);
        printf("Here is the list of your books sorted by title:\n");
        title_sort(library, count);
        for (index = 0; index < count; index++)
            printf("%s by %s: $%.2f\n", library[index]->title,
                   library[index]->author, library[index]->value);
        printf("Here is the list of your books sorted by value:\n");
        value_sort(library, count);
        for (index = 0; index < count; index++)
            printf("%s by %s: $%.2f\n", library[index]->title,
                    library[index]->author, library[index]->value);
    }
    else
        printf("No books? Too bad.\n");

    return 0;
}

char * my_gets(char *string, int n)
{
    // wrapper for fgets that replaces first newline with null

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

void title_sort(struct book ** bp, int count)
{
    struct book * temp;
    for (int i = 0; i < count - 1; i ++)
        for (int j = i + 1; j < count; j++){
            if (tolower(bp[i]->title[0]) > tolower(bp[j]->title[0])){
                temp = bp[i];
                bp[i] = bp[j];
                bp[j] = temp;
            }
    }
}

void value_sort(struct book ** bp, int count)
{
    struct book * temp;
    for (int i = 0; i < count - 1; i++)
        for (int j = i + 1; j < count; j++){
            if (bp[j]->value > bp[i]->value)
                temp = bp[j];
                bp[j] = bp[i];
                bp[i] = temp; // Swap the order of the array of pointers

    }
}