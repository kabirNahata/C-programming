#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* work(void* arg) {
    int id = (int)arg;
    printf("Thread %d starting work...\n", id);
    sleep(2);  // simulate some processing time
    printf("Thread %d finished work.\n", id);
    return NULL;
}

int main() {
    pthread_t threads[4];
    int ids[4] = {1, 2, 3, 4};

    for (int i = 0; i < 4; i++) {
        pthread_create(&threads[i], NULL, work, &ids[i]);
    }

    for (int i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All threads completed.\n");
    return 0;
}