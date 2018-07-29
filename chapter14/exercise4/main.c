// C Primer Plus
// Chapter 14 Exercise 4:

// Write a program that creates a structure template with two members according
// to the following criteria:
// a. The first member is a social security number. The second member is a
// structure with three members. Its first member contains a first name, its
// second member contains a middle name, and its final member contains a last
// name. Create and initialize an array of five such structures. Have the
// program print the data in this format:
// Dribble, Flossie M. –– 302039823
// Only the initial letter of the middle name is printed, and a period is
// added. Neither the initial (of course) nor the period should be printed if
// the middle name member is empty. Write a function to do the printing; pass
// the structure array to the function.
// b. Modify part a. by passing the structure value instead of the address.\

// Created by Kurt Reed

#include <stdio.h>
#include <ctype.h>

#define STUDENT_POPULATION 5

struct name {
    char first_name[20];
    char middle_name[20];
    char last_name[20];
};

struct user {
    int social_sec;
    struct name user_name;
};

void display_users(struct user * c_user, int n);

int main() {
    struct user students[STUDENT_POPULATION] =
            {
                    {50365834, {"David","Allen","Coe"}},
                    {50364245, {"Countrey","Lee","Smith"}},
                    {50236464, {"Pete","Oswalt","Timmy"}},
                    {85545673, {"Sebastian","Riley","Turnipseed"}},
                    {97547664, {"Pat","Camerson","Harris"}}
            };
    display_users(students, STUDENT_POPULATION);

    return 0;
}

void display_users(struct user * c_user, int n)
{
    for (int i = 0; i < n; i++){
        printf("%s, %s %c. -- %d\n", c_user[i].user_name.last_name,
               c_user[i].user_name.first_name,
               toupper(c_user[i].user_name.middle_name[0]),
               c_user[i].social_sec);

    }
}