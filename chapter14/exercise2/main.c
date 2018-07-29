// C Primer Plus
// Chapter 14 Exercise 2:

// Write a program that prompts the user to enter the day, month, and year. The
// month can be a month number, a month name, or a month abbreviation. The
// program then should return the total number of days in the year up through
// the given day. (Do take leap years into account.)

// Created by Kurt Reed

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MONTHS 12

struct date{
    int day;
    char month[15];
    int year;
};

int days_up_to(struct date *);
int is_leap_year(int year);
void get_month_name(char * str);
void get_day(int *);
void get_year(int *);
char * to_lower_str(char * str);
void eatline(void);


int days_in_month[MONTHS] = {31,28,31,30,31,30,31,31,30,31,30,31};
char *names[MONTHS] = {"January", "February", "March", "April", "May",
                       "June", "July", "August", "September", "October",
                       "November", "December"};


int main() {
    int year, day, total_days;
    char month[15];
    struct date my_date;

    get_day(&my_date.day);
    get_month_name(my_date.month);
    get_year(&my_date.year);

    if (is_leap_year(year))
    {
        days_in_month[1] = 29; // It is a leap year
    }
    total_days = days_up_to(&my_date);
    printf("There are %d days from January 1, %d to %s %d, %d.\n", total_days,
            my_date.year, my_date.month, my_date.day, my_date.year);

    return 0;
}

int days_up_to(struct date * date1)
{
    // Takes a date structure and returns the number of days
    // in that year beginning at jan 1st up to and including
    // the date specified.
    int i = 0;
    int total = 0;

    while (strcmp(date1->month, names[i]) != 0)
    {
        total += days_in_month[i];
        i++;
    }
    total += date1->day; // Add the last month to total

    return total;
}

int is_leap_year(int year)
{
    // Tests if the year is a leap year.
    // Returns 0 if it is not.
    // Returns 1 if it is a leap year.

    int value = 0;
    if (year % 4 == 0)
        if (year % 100 == 0)
            if (year %400 == 0)
                value =1;

    return 1;
}

void get_month_name(char * str)
{
    // Prompts user for month and stores it at
    // the location pointed to in str in the
    // title format.
    puts("Please enter the name of a month: ");
    gets(str);
    str = to_lower_str(str);
    str[0] -= 32;
}

void get_day(int * p)
{
    // prompts and receives day data from the user
    // clears buffer.
    puts("Enter the day:");
    scanf("%d", p);
    eatline();
}

void get_year(int * p)
{
    // prompts and receives year data from the user
    // clears buffer.
    puts("Enter the year:");
    scanf("%d", p);
    eatline();
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

void eatline(void)
{
    while (getchar() != '\n')
        continue;
}