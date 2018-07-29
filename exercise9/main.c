// C Primer Plus
// Chapter 14 Exercise 9:

// Colossus Airlines (from exercise 8) acquires a second plane (same capacity)
// and expands its service to four flights daily (Flights 102, 311, 444, and
// 519). Expand the program to handle four flights. Have a top-level menu that
// offers a choice of flights and the option to quit. Selecting a particular
// flight should then bring up a menu similar to that of exercise 8. However,
// one new item should be added: confirming a seat assignment. Also, the quit
// choice should be replaced with the choice of exiting to the top-level menu.
// Each display should indicate which flight is currently being handled. Also,
// the seat assignment display should indicate the confirmation status.
//
// Created by Kurt on 7/28/2018.
//
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "seat_reservation.h"
#include "my_io.h"

#define NUM_SEATS 12
#define NUM_FLIGHTS 4

void display_menu(plane flights[], int num_seats); // n is the size of the array.
void display_num_empty_seats(seat *, int n);
void display_empty_seats(seat *, int n);
void show_alphabetical_list(seat *, int n);
void read_seat_data(plane flights[], int num_seats, int num_flights);
void assign_customer(seat seats[], int n);
void delete_assignment(seat seats[], int n);
void confirm_assignment(seat seats[]);

int main() {
    plane flights[NUM_FLIGHTS];
    read_seat_data(flights, NUM_SEATS, NUM_FLIGHTS);

    display_menu(flights, NUM_SEATS);

    return 0;
}

void display_menu(plane flights[], int num_seats)
{
    bool prompting;
    while (1) {
        int flight_choice;
        fputs("To choose a flight enter its number label:\n", stdout);
        fprintf(stdout, "1) Flight %d\n", flights[0].flightnum);
        fprintf(stdout, "2) Flight %d\n", flights[1].flightnum);
        fprintf(stdout, "3) Flight %d\n", flights[2].flightnum);
        fprintf(stdout, "4) Flight %d\n", flights[3].flightnum);
        fputs("5) Quit\n", stdout);
        while ((scanf("%d", &flight_choice)) != 1 || flight_choice > 4
               || flight_choice < 1) {
            if (flight_choice == 5)
                return;
            fputs("Please enter valid number between 1 and 4:\n", stdout);
            eatline();
        }
        eatline();
        flight_choice--;
        prompting = true;

        while (prompting) {
            char option;
            fprintf(stdout, "To choose a function for flight %d enter its letter "
                            "label:\n", flights[flight_choice].flightnum);
            fputs("a) Show number of empty seats\n", stdout);
            fputs("b) Show list of empty seats\n", stdout);
            fputs("c) Show alphabetical list of seats\n", stdout);
            fputs("d) Assign a customer to a seat assignment\n", stdout);
            fputs("e) Delete a seat assignment\n", stdout);
            fputs("f) Confirm a seat.\n", stdout);
            fputs("g) Exit to flight menu.\n", stdout);

            while ((scanf("%c", &option)) != 1) {
                fputs("Please enter valid character between a and f\n", stdout);
                eatline();
            }
            eatline();

            switch (tolower(option)) {
                case 'a' :
                    display_num_empty_seats(flights[flight_choice].seat, num_seats);
                    break;
                case 'b' :
                    display_empty_seats(flights[flight_choice].seat, num_seats);
                    break;
                case 'c' :
                    show_alphabetical_list(flights[flight_choice].seat, num_seats);
                    break;
                case 'd' :
                    assign_customer(flights[flight_choice].seat, num_seats);
                    break;
                case 'e' :
                    delete_assignment(flights[flight_choice].seat, num_seats);
                    break;
                case 'f' :
                    confirm_assignment(flights[flight_choice].seat);
                    break;
                case 'g' :
                    prompting = false;
                    break;
                default :
                    printf("%c is an invalid character\n", option);
                    break;
            }
            putchar('\n');
        }
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

void read_seat_data(plane flights[], int num_seats, int num_flights)
{

    FILE *fp;
    char *filepath = "C:/Users/Kurt/CLionProjects/C_Primer_Chapter14/exercise9"
                     "/seat_data.txt";
    if ((fp = fopen(filepath, "r")) == NULL) {
        fprintf(stderr, "Could not open file 'roster.txt'.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < NUM_FLIGHTS; i++) {
        fscanf(fp, "%d", &flights[i].flightnum);
        for (int j = 0; j < NUM_SEATS; j++){
                fscanf(fp, "%u %d", &flights[i].seat[j].id, &flights[i].seat[j].assigned);
                if (flights[i].seat[j].assigned) {
                    fscanf(fp, "%s %s", &flights[i].seat[j].first_name,
                           &flights[i].seat[j].last_name);
                } else {
                    strcpy(&flights[i].seat[j].first_name, "");
                    strcpy(&flights[i].seat[j].last_name, "");
                }
            }

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

void confirm_assignment(seat seats[])
{
    unsigned int id;
    char first_name[20];
    char last_name[20];

    fputs("Please enter the seat ID you wish to confirm:\n", stdout);
    while(fscanf(stdin, "%u", &id) != 1 || id > NUM_SEATS || id < 1){
        fputs("Please enter a valid seat ID:\n", stdout);
        eatline();
    }
    eatline();
    fputs("Please enter the first name:\n", stdout);
    while(my_gets(first_name, 20) == NULL){
        fputs("Please enter a valid name:\n", stdout);
    }
    fputs("Please enter the last name:\n", stdout);
    while(my_gets(last_name, 20) == NULL){
        fputs("Please enter a valid name:\n", stdout);
    }

    if(strcmp(seats[id -1].first_name, first_name) == 0 &&
            strcmp(seats[id - 1].last_name, last_name) == 0)
    {
        fputs("Confirmed.\n", stdout);
    }
    else
        fputs("The seat cannot be confirmed.\n", stdout);
}