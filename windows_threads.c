#include <windows.h>
#include <stdio.h>

DWORD WINAPI Task1(LPVOID lpParam) {
    for (int i = 0; i < 5; i++) {
        printf("Thread 1: %d\n", i);
        Sleep(500); // 0.5 second
    }
    return 0;
}

DWORD WINAPI Task2(LPVOID lpParam) {
    for (int i = 0; i < 5; i++) {
        printf("Thread 2: %d\n", i);
        Sleep(500);
    }
    return 0;
}

int main() {
    HANDLE t1 = CreateThread(NULL, 0, Task1, NULL, 0, NULL);
    HANDLE t2 = CreateThread(NULL, 0, Task2, NULL, 0, NULL);

    // Wait for threads to complete
    WaitForSingleObject(t1, INFINITE);
    WaitForSingleObject(t2, INFINITE);

    printf("Main thread done.\n");
    return 0;
}