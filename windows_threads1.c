#include <stdio.h>
#include <pthread.h>

void* task1(void* arg) {
    for (int i = 0; i < 5; i++) {
        printf("Thread 1 - Count: %d\n", i);
    }
    return NULL;
}

void* task2(void* arg) {
    for (int i = 0; i < 5; i++) {
        printf("Thread 2 - Count: %d\n", i);
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;

    // Create 2 threads
    pthread_create(&t1, NULL, task1, NULL);
    pthread_create(&t2, NULL, task2, NULL);

    // Wait for both threads to finish
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Main thread finished.\n");
    return 0;
}
