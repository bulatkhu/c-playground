#define _XOPEN_SOURCE 700
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
// #include "sem.h"

#define THREAD_NUM 16

sem_t semaphore;

static void *routine(void *args) {
    int queue_num = *(int*) args;
    printf("(%d) Waits in the login queue\n", queue_num);
    sem_wait(&semaphore);
    printf("(%d) Logged in\n", queue_num);
    printf("Hello from thread %d\n", queue_num);
    sleep(rand() % 5 + 1);
    printf("(%d) Logged out\n", queue_num);

    sem_post(&semaphore);
    free(args);
    return NULL;
}

int main() {
    pthread_t th[THREAD_NUM];
    sem_init(&semaphore, 0, 2);

    int i;

    for (i = 0; i < THREAD_NUM; i++) {
        int* a = malloc(sizeof(THREAD_NUM));
        *a = i;

        if (pthread_create(&th[i], NULL, routine, a) != 0) {
            perror("Failed to create thread");
        }
        pthread_detach(th[i]);
    }

    // with pthread_join will wait till all threads are ready and will give back the result
    // for (i = 0; i < THREAD_NUM; i++) {
    //     if (pthread_join(th[i], NULL) != 0) {
    //         perror("Failed to join thread");
    //     }
    // }
    sem_destroy(&semaphore);

    printf("end");
    sleep(10);
    return 0;
}

