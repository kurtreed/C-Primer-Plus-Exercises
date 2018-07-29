// C Primer Plus
// Chapter 14 Exercise 6:

// A text file holds information about a softball team. Each line has data
// arranged as follows:
// 	4 Jessie Joybat 5 2 1 1
// The first item is the player’s number, conveniently in the range 0–18. The
// second item is the player’s first name, and the third is the player’s last
// name. Each name is a single word. The next item is the player’s official
// times at bat, followed by the number of hits, walks, and runs batted in
// (RBIs). The file may contain data for more than one game, so the same player
// may have more than one line of data, and there may be data for other players
// between those lines. Write a program that stores the data into an array of
// structures. The structure should have members to represent the first and
// last names, the at bats, hits, walks, and RBIs (runs batted in), and the
// batting average (to be calculated later). You can use the player number as
// an array index. The program should read to end- of-file, and it should keep
// cumulative totals for each player.

// The world of baseball statistics is an involved one. For example, a walk or
// reaching base on an error doesn’t count as an at-bat but could possibly
// produce an RBI. But all this program has to do is read and process the data
// file, as described next, without worrying about how realistic the data is.

// The simplest way for the program to proceed is to initialize the structure
// contents to zeros, read the file data into temporary variables, and then add
// them to the contents of the corresponding structure. After the program has
// finished reading the file, it should then calculate the batting average for
// each player and store it in the corresponding structure member. The batting
// average is calculated by dividing the cumulative number of hits for a player
// by the cumulative number of at-bats; it should be a floating-point
// calculation. The program should then display the cumulative data for each
// player along with a line showing the combined statistics for the entire
// team.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "baseball_player.h"

#define TEAMSIZE 2 // Remember to change this

void read_basbeball_stats(ball_player *);
void calc_batting_varages(ball_player *);
void display_data(ball_player *);

int main() {

    ball_player players[TEAMSIZE];
    for (int i = 0; i < TEAMSIZE; i++)
        players[i] = (ball_player) {0, "", "", 0, 0, 0, 0, 0};

    read_basbeball_stats(players);
    calc_batting_varages(players);
    display_data(players);
    return 0;
}

void read_basbeball_stats(ball_player * players)
{
    FILE *fp;
    char *filepath = "C:/Users/Kurt/CLionProjects/C_Primer_Chapter14/exercise6"
                     "/baseball_stats.txt";

    if ((fp = fopen(filepath, "r")) == NULL)
    {
        fprintf(stderr, "Could not open file 'roster.txt'.\n");
        exit(EXIT_FAILURE);
    }

    fp = fopen(filepath, "r");

    unsigned int tmp_number, tmp_times_at_bat, tmp_hits, tmp_walks, tmp_RBIs;
    char tmp_first_name[20];
    char tmp_last_name[20];
    int found_player = 0; // This is a bool

    while(fscanf(fp, "%u %s %s %u %u %u %u", &tmp_number, &tmp_first_name,
            &tmp_last_name, &tmp_times_at_bat, &tmp_hits, &tmp_walks,
                 &tmp_RBIs) == 7)
    {
        found_player = 0;

        for (int i = 0; i < TEAMSIZE; i++){
            if (tmp_number == players[i].number){
                players->times_at_bat += tmp_times_at_bat;
                players->hits += tmp_hits;
                players->walks += tmp_walks;
                players->RBIs += tmp_RBIs;
                found_player = 1;
                break;
            }
        }
        if (!found_player){
            int i;
            for(i = 0; i < TEAMSIZE; i++){
                if (players[i].number == 0)
                    break;
            }
            players[i].number = tmp_number;
            strcpy(players[i].first_name, tmp_first_name);
            strcpy(players[i].last_name, tmp_last_name);
            players[i].times_at_bat = tmp_times_at_bat;
            players[i].hits = tmp_hits;
            players[i].walks = tmp_walks;
            players[i].RBIs = tmp_RBIs;
        }
    }

    if (fclose(fp) != 0)
        fprintf(stderr, "Error closing file.\n");
}

void calc_batting_varages(ball_player * players)
{
    while (players->first_name[0] != '\0'){
        players->batting_average = (float)players->hits / players->times_at_bat;
        players++;
    }
}

void display_data(ball_player * players)
{
    float team_bat_ave = 0;
    for (int i = 0; i < TEAMSIZE; i++){
        printf("%s %s\n", players[i].first_name, players[i].last_name);
        printf("Batting Average: %.3f\n", players[i].batting_average);
        printf("Walks: %u\n", players[i].walks);
        printf("RBIs: %u\n", players[i].RBIs);
        team_bat_ave += players[i].batting_average;
        putchar('\n');
    }

    team_bat_ave = team_bat_ave / TEAMSIZE;
    printf("The team's batting average is %.3f.\n", team_bat_ave);
}