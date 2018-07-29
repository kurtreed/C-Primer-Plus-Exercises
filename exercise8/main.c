// C Primer Plus
// Chapter 14 Exercise 8:

// The Colossus Airlines fleet consists of one plane with a seating capacity of
// 12. It makes one flight daily. Write a seating reservation program with the
// following features:

// a. The program uses an array of 12 structures. Each structure should hold a
// seat identification number, a marker that indicates whether the seat is
// assigned, the last name of the seat holder, and the first name of the seat
// holder.

// b. The program displays the following menu:
// 	To choose a function, enter its letter label:
// 	a) Show number of empty seats
// 	b) Show list of empty seats
// 	c) Show alphabetical list of seats
// 	d) Assign a customer to a seat assignment
//  e) Delete a seat assignment
// 	f) Quit

// c. The program successfully executes the promises of its menu. Choices d)
// and e) require additional input, and each should enable the user to abort an
// entry.

// d. After executing a particular function, the program shows the menu again,
// except for choice f).

// e. Data is saved in a file between runs. When the program is restarted, it
// first loads in the data, if any, from the file.

// Creating by Kurt Reed

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "seat_reservation.h"
#include "my_io.h"

#define NUM_SEATS 12

void display_menu(seat *, int n); // n is the size of the array.
void display_num_empty_seats(seat *, int n);
void display_empty_seats(seat *, int n);
void show_alphabetical_list(seat *, int n);
void read_seat_data(seat seats[], int n);
void assign_customer(seat seats[], int n);
void delete_assignment(seat seats[], int n);

int main() {
    seat colo_seats[NUM_SEATS];
    read_seat_data(colo_seats, NUM_SEATS);

    display_menu(colo_seats, NUM_SEATS);

    return 0;
}

void display_menu(seat * seats, int n)
{
    while (1) {
        char option;
        fputs("To choose a function enter its letter label:\n", stdout);
        fputs("a) Show number of empty seats\n", stdout);
        fputs("b) Show list of empty seats\n", stdout);
        fputs("c) Show alphabetical list of seats\n", stdout);
        fputs("d) Assign a customer to a seat assignment\n", stdout);
        fputs("e) Delete a seat assignment\n", stdout);
        fputs("f) Quit\n", stdout);

        while ((scanf("%c", &option)) != 1) {
            fputs("Please enter valid character between a and f\n", stdout);
            eatline();
        }
        eatline();

        switch (tolower(option)) {
            case 'a' :
                display_num_empty_seats(seats, n);
                break;
            case 'b' :
                display_empty_seats(seats, n);
                break;
            case 'c' :
                show_alphabetical_list(seats, n);
                break;
            case 'd' :
                assign_customer(seats, n);
                break;
            case 'e' :
                delete_assignment(seats, n);
                break;
            case 'f' :
                return;
            default :
                printf("%c is an invalid character\n", option);
                break;
        }
        putchar('\n');
    }
}

void display_num_empty_seats(seat *seats, int n)
{
    unsigned short empty_seats = 0;
    for (int i = 0; i < n; i++)
    {
        if (seats[i].assigned == 0)
            empty_seats++;
    }
    if (empty_seats == 0)
        fprintf(stdout, "No seats are empty.\n");
    else
        fprintf(stdout, "There are %u empty seats.\n", empty_seats);
}

void display_empty_seats(seat *seats, int n)
{
    int no_open_seats = 1;

    for (int i = 0; i < n; i++)
    {
        if (seats[i].assigned == 0) {
            fprintf(stdout, "Seat %d is empty.\n", seats[i].id);
            no_open_seats = 0;
        }
    }
    if (no_open_seats)
        fprintf(stdout, "No seats are empty.\n");
}

void show_alphabetical_list(seat * seats, int n)
{
    seat * seat_ptrs[NUM_SEATS];

    // Initialize seat_ptrs
    for (int i = 0; i < NUM_SEATS; i++) {
        seat_ptrs[i] = (seats + i);
    }
    // Sorts according to last names.
    seat ** temp;
    char *test_string1;
    char *test_string2;

    // Sort the array of pointers.
    int i, j, test;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            test_string1 = seat_ptrs[i]->last_name;
            test_string2 = seat_ptrs[j]->last_name;
            test = strcmp(seat_ptrs[i]->last_name, seat_ptrs[j]->last_name);
            if (test > 0) {
                temp = seat_ptrs[i];
                seat_ptrs[i] = seat_ptrs[j];
                seat_ptrs[j] = temp;
            }
        }
    }

    fputs("The seats sorted according to last name.\n", stdout);
    for (i = 0; i < n; i++){
        if (seat_ptrs[i]->assigned) {
            fprintf(stdout, "%s, %s seat id: %u\n", seat_ptrs[i]->last_name,
                    seat_ptrs[i]->first_name, seat_ptrs[i]->id);
        }
    }

}

void read_seat_data(seat seats[], int n)
{

    FILE *fp;
    char *filepath = "C:/Users/Kurt/CLionProjects/C_Primer_Chapter14/exercise8"
                     "/seat_data.txt";
    if ((fp = fopen(filepath, "r")) == NULL) {
        fprintf(stderr, "Could not open file 'roster.txt'.\n");
        exit(EXIT_FAILURE);
    }

    unsigned int tmp_id;
    int tmp_assigned, num;
    char temp_first[20];
    char temp_last[20];

    int i = 0;
    while((fscanf(fp, "%u %d", &tmp_id, &tmp_assigned)) == 2)
    {
        if (tmp_assigned){
            fscanf(fp, "%s %s", &seats[i].first_name, &seats[i].last_name);
            seats[i].id = tmp_id;
            seats[i].assigned = tmp_assigned;
        }
        else {
            strcpy(&seats[i].first_name, "");
            strcpy(&seats[i].last_name, "");
            seats[i].id = tmp_id;
            seats[i].assigned = tmp_assigned;
        }
        i++;
    }

    if (fclose(fp) != 0)
        fprintf(stderr, "Error closing file.\n");
}

void assign_customer(seat seats[], int n)
{
    unsigned int id;
    char first_name[20];
    char last_name[20];

    fputs("Please enter the seat ID you wish to assign:\n", stdout);
    while(fscanf(stdin, "%u", &id) != 1 || id > NUM_SEATS || id < 1){
        fputs("Please enter a valid seat ID:\n", stdout);
        eatline();
    }
    eatline();
    fputs("Please enter the first name:\n", stdout);
    while(fscanf(stdin, "%s", first_name) != 1){
        fputs("Please enter a valid name:\n", stdout);
        eatline();
    }
    eatline();
    fputs("Please enter the last name:\n", stdout);
    while(fscanf(stdin, "%s", last_name) != 1){
        fputs("Please enter a valid name:\n", stdout);
        eatline();
    }
    eatline();

    strcpy(seats[id - 1].first_name, first_name);
    strcpy(seats[id - 1].last_name, last_name);
    seats[id - 1].assigned = 1;
    fprintf(stdout, "%s %s has been assigned to seat %u.\n", first_name,
            last_name, id);
}

void delete_assignment(seat seats[], int n)
{
    unsigned int id;

    fputs("Please enter the seat ID of the assignment you wish to delete:\n",
          stdout);
    while(fscanf(stdin, "%u", &id) != 1 || id > NUM_SEATS || id < 1){
        fputs("Please enter a valid seat ID:\n", stdout);
        eatline();
    }
    eatline();
    strcpy(seats[id - 1].first_name, "");
    strcpy(seats[id - 1].first_name, "");
    seats[id - 1].assigned = 0;
}