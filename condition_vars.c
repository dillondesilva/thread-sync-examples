/*
Author: Dillon de Silva
Description: This program demonstrates how condition variables
can be used for thread synchronisation and how the corresponding
mutex needs to be handled
*/
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_t thread_1;
pthread_t thread_2;
pthread_cond_t my_cond;
pthread_mutex_t my_mutex;

int important_num = 0;

void thread_func() {
    puts("New thread spawned");
    pthread_mutex_lock(&my_mutex);
    if (pthread_cond_wait(&my_cond, &my_mutex) != 0) {
        exit(-1);
    }

    important_num++;
    printf("Thread says: Important num has value %d\n", important_num);

    // Try commenting the mutex unlock below and see what happens.
    // Do we reach a deadlock? Remember once a thread continues execution
    // after a condition variable is signaled, it re-acquires the mutex lock
    pthread_mutex_unlock(&my_mutex);
    pthread_exit(NULL);
}

int main(void) {
    pthread_mutex_init(&my_mutex, NULL);
    pthread_cond_init(&my_cond, NULL);

    pthread_create(&thread_1, NULL, (void*)thread_func, NULL);
    pthread_create(&thread_2, NULL, (void*)thread_func, NULL);
    sleep(1);
    printf("Main says: Important num has value %d\n", important_num);

    /*
    Try the following:
    1. Using pthread_cond_broadcast
    2. Using only one call to pthread_cond_signal
    3. Using two calls to pthread_cond_signal
    */
    pthread_cond_broadcast(&my_cond); // Uncomment this and play with signal too!
    // pthread_cond_signal(&my_cond);
    // pthread_cond_signal(&my_cond);
    pthread_join(thread_1, NULL);
    pthread_join(thread_2, NULL);

    pthread_mutex_destroy(&my_mutex);
    pthread_cond_destroy(&my_cond);
    pthread_exit(0);
}
