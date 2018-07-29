//
// Created by Kurt on 7/25/2018.
//

#ifndef EXERCISE6_BASEBALL_PLAYER_H
#define EXERCISE6_BASEBALL_PLAYER_H

#endif //EXERCISE6_BASEBALL_PLAYER_H

#include <stdlib.h>
#include <stdio.h>


#define NAME_LEN 20

struct BallPlayer {
    unsigned int number;
    char first_name[NAME_LEN];
    char last_name[NAME_LEN];
    unsigned int times_at_bat, hits, walks, RBIs;
    float batting_average;
};

typedef struct BallPlayer ball_player;