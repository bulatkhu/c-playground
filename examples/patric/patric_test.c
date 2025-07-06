#define _XOPEN_SOURCE 700
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "sem.h"
#include "triangle.c"

struct Counter {
    int boundry;
    int interior;
};

struct Counter myCounter = {
    .boundry = 0,
    .interior = 0
};

void *callback(int boundry, int interior) {
    myCounter.boundry += boundry;
    myCounter.interior += interior;
    return NULL;
};

int main() {
    // SEM *sem = semCreate(1);

    struct triangle tr = {
        .point = {
            { 1, 1 },
            { 2, 4 },
            { 7, 5 }
        }
    };

    // V(sem);
    countPoints(&tr, callback);
    printf("boundry %d | interior %d \n", myCounter.boundry, myCounter.interior);
    myCounter.boundry = 0;
    myCounter.interior = 0;
    // P(sem);

    // semDestroy(sem);
}
