#define _XOPEN_SOURCE 700
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "sem.h"
#include "triangle.h"

struct Counter {
    int boundry;
    int interior;
};

SEM *sem;

struct Counter myCounter = {
    .boundry = 0,
    .interior = 0
};

void *callback(int boundry, int interior) {
    myCounter.boundry += boundry;
    myCounter.interior += interior;
    return NULL;
}

static void *routine(void *args) {
    // struct triangle tr = *(struct triangle*) args;
    V(sem);
    printf("tr\n");
    P(sem);
    return NULL;
}

int main() {
    pthread_t th[1];
    sem = semCreate(1);

    struct triangle tr = {
        .point = {
            { 1, 1 },
            { 2, 4 },
            { 7, 5 }
        }
    };

    pthread_create(&th[1], NULL, &routine, &tr);

    pthread_join(th[1], NULL);

    printf("boundry %d | interior %d \n", myCounter.boundry, myCounter.interior);
    myCounter.boundry = 0;
    myCounter.interior = 0;

    semDestroy(sem);
}
