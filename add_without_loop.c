#include <stdio.h>

int main() 
{
    int n;
    printf("Enter a limit of number you want to add: ");
    scanf("%i\n", &n);

    int sum = n * (n + 1) / 2;

    printf("Sum = %i\n", sum);
    return 0;
}