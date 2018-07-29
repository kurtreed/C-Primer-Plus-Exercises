#ifndef EXERCISE5_NAME_H
#define EXERCISE5_NAME_H

#endif //EXERCISE5_NAME_H

#define NAME_LEN 20

struct Name{
    char first[NAME_LEN];
    char last[NAME_LEN];
};
typedef struct Name NAME;

struct Student{
    NAME name;
    float grades[3];
    float average;
};
typedef struct Student STUDENT;