// C Primer Plus
// Chapter 14 Exercise 1:

/* Redo review question 5, but make the argument the spelled-out
   name of the month instead of the month number.  */

// Created by Kurt Reed

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MONTHS 12

int days_up_to(const char *);
char * to_lower_str(char * str);

struct month {
    	char name[20];
    	char abr[4];
    	int month_no;
    	int days;
     };

struct month months[MONTHS];

int days_in_month[MONTHS] = {31,28,31,30,31,30,31,31,30,31,30,31};
char *names[MONTHS] = {"January", "February", "March", "April", "May",
                       "June", "July", "August", "September", "October",
                       "November", "December"};
char *abrevs[MONTHS] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul",
                        "Aug", "Sep", "Oct", "Nov", "Dec"};

int main() {
    char * month_name;
    char * test = "Testing";

    puts("Please enter the name of a month: ");
    gets(month_name);
    month_name = to_lower_str(month_name);
    month_name[0] -= 32; // Converts the first letter to uppercase
    // Month Name is now in the proper form.
    printf("There are %d days up to and including %s.\n", days_up_to(month_name),
            month_name);

    return 0;
}

char * to_lower_str(char * str)
{
    // converts a string to all lowercase characters
    for (int i = 0; str[i]; i++) // goes until it reaches the null character (equal to 0)
    {
        str[i] = (char)tolower(str[i]);
    }
    return str;
}

int days_up_to(const char * month)
{
    int i = 0;
    int total = 0;

    while (strcmp(month, names[i]) != 0)
    {
        total += days_in_month[i];
        i++;
    }
    total += days_in_month[i]; // Add the last month to total

    return total;
}