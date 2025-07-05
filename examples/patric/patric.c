#define _XOPEN_SOURCE 700
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "sem.h"

void *computation(void *add);

int main() {
    pthread_t thread1;
    long value1 = 1;

    pthread_t thread2;
    long value2 = 2;

    pthread_create(&thread1, NULL, computation, (void *) &value1);
    pthread_create(&thread2, NULL, computation, (void *) &value2);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}

void *computation(void *add) {
    long *add_num = (long *) (add);
    printf("Add: %ld \n", *add_num);
    return NULL;
}