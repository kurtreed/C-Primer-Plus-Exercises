//
// Created by Kurt on 7/27/2018.
//

#ifndef EXERCISE8_SEAT_RESERVATION_H
#define EXERCISE8_SEAT_RESERVATION_H

#endif //EXERCISE8_SEAT_RESERVATION_H

struct seat_t{
    unsigned int id;
    int assigned; // 1 if it is assigned, 0 if not.
    char first_name[20];
    char last_name[20];
};
typedef struct seat_t seat;