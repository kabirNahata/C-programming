#include <stdio.h>

int main() {
    int sum = 0;

    for (int i = 1; i <= 100; i++)
    {
        sum += i;
    }

    printf("Sum = %i\n", sum);
    return 0;
}
