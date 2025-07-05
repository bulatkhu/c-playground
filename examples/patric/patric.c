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

    // computation((void*) &value1);
    // computation((void*) &value2);
    // $ gcc -o d patric.c
    // $ time ./d
    // Add: 1
    // Add: 2
    //
    // real    0m4.618s
    // user    0m0.000s
    // sys     0m0.031s


    // pthread_create(&thread1, NULL, computation, (void *) &value1);
    // pthread_create(&thread2, NULL, computation, (void *) &value2);
    //
    // pthread_join(thread1, NULL);
    // pthread_join(thread2, NULL);
    // $ time ./d
    // Add: 1
    // Add: 2
    //
    // real    0m2.333s
    // user    0m0.031s
    // sys     0m0.015s


    pthread_create(&thread1, NULL, computation, (void *) &value1);
    pthread_join(thread1, NULL);

    pthread_create(&thread2, NULL, computation, (void *) &value2);
    pthread_join(thread2, NULL);
    // $ time ./d
    // Add: 1
    // Add: 2
    //
    // real    0m4.615s
    // user    0m0.000s
    // sys     0m0.031s



    return 0;
}

void *computation(void *add) {
    long sum = 0;
    long *add_num = (long *) (add);

    for (long i = 0; i < 1000000000; i++)
        sum += *add_num;

    printf("Add: %ld \n", *add_num);
    return NULL;
}