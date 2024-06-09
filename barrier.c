/*
Author: Dillon de Silva
Description: This program demonstrates how barriers
can be a useful way to sync multiple threads together.
*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_t thread_1;
pthread_t thread_2;
pthread_t thread_3;

pthread_barrier_t my_barrier;

void thread_func() {
    // The first message will print as soon as the thread is spun up.
    // Can you predict when the next message will print?
    puts("New thread spun up. Waiting for more threads to reach barrier");
    pthread_barrier_wait(&my_barrier);
    puts("All threads synced at barrier - Let's go!");
    pthread_exit(NULL);
}

int main(void) {
    // Initialise our barrier
    pthread_barrier_init(&my_barrier, NULL, 3);

    // Launch threads
    pthread_create(&thread_1, NULL, (void*)thread_func, NULL);
    pthread_create(&thread_2, NULL, (void*)thread_func, NULL);
    pthread_create(&thread_3, NULL, (void*)thread_func, NULL);

    // Join threads once completed
    pthread_join(thread_1, NULL);
    pthread_join(thread_2, NULL);
    pthread_join(thread_3, NULL);
    exit(0);
}
