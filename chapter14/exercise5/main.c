// C Primer Plus
// Chapter 14 Exercise 5:

// Write a program that fits the following recipe:
// a. Externally define a name structure template with two members: a string to
// 	hold the first name and a string to hold the second name.
// b. Externally define a student structure template with three members: a name
// 	structure, a grade array to hold three floating-point scores, and a
// 	variable to hold the average of those three scores.
// c. Have the main() function declare an array of CSIZE (with CSIZE = 4)
// 	student structures and initialize the name portions to names of your
// 	choice. Use functions to perform the tasks described in parts d., e.,
// 	f., and g.
// d. Interactively acquire scores for each student by prompting the user with
// 	a student name and a request for scores. Place the scores in the grade
// 	array portion of the appropriate structure. The required looping can be
// 	done in main() or in the function, as you prefer.
// e. Calculate the average score value for each structure and assign it to the
// 	proper member.
// f. Print the information in each structure.
// g. Print the class average for each of the numeric structure members.

// Created by Kurt Reed

#include <stdio.h>
#include "name.h"

#define CSIZE 4

void get_grades(STUDENT *);
void assign_averages(STUDENT *);
void print_info(STUDENT *);
void eatline(void);
void print_class_average(STUDENT *);

int main() {
    STUDENT student_arr[CSIZE] = {
            {.name = {"Kurt", "Reed"}},
            {.name = {"Gerald", "Maxwell"}},
            {.name = {"Jeff", "Reed"}},
            {.name = {"Jim", "Bingbong"}}
    };

    get_grades(student_arr);
    assign_averages(student_arr);
    print_info(student_arr);
    print_class_average(student_arr);

    return 0;
}

void get_grades(STUDENT * student)
{
    for (int i = 0; i < CSIZE; i ++){
        printf("Please enter the grades for %s %s.\n", student->name.first,
               student->name.last);
        while (scanf("%f %f %f", &student->grades[0], &student->grades[1],
                        &student->grades[2]) != 3)
        {
            printf("Invalid input. Enter three grades: ");
            eatline();
        }
        eatline();
        student++;
    }
}

void assign_averages(STUDENT *student)
{
    for (int i = 0; i < CSIZE; i++) {
        float average = (student->grades[0] + student->grades[1] + student->grades[2])
                                                                  / 3.0;
        student->average = average;
        student++;
    }
}

void print_info(STUDENT *student)
{
    for (int i = 0; i < CSIZE; i++) {
        printf("%s %s's average grade is %.3f%%.\n",
               student->name.first, student->name.last,
               student->average);
        student++;
    }
}

void print_class_average(STUDENT *student){
    float grade_total = 0;
    float ave_class_grade;
    for (int i = 0; i < CSIZE; i++) {
        grade_total += student->average;
        student++;
    }
    ave_class_grade = grade_total / CSIZE;
    printf("The class average is %.3f%%.\n", ave_class_grade);
}

void eatline(void)
{
    // clears input
    while (getchar() != '\n')
        continue;
}
