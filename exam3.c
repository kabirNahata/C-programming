#include <stdio.h>

int main(){
    int n, c;
    int a = 1;
    int b = 1;

    printf("Enter the length: ");
    scanf("%d", &n);

    if(n <= 0){
        printf("LEngth must be a positive integer.\n");
        return 1;
    }

    int fib_series[n];

    fib_series[0] = 1;
    fib_series[1] = 1;

    for (int i = 2; i < n; i++){
        fib_series[i] = fib_series[i-1] + fib_series[i-2];
    }

    printf("Fibonacci Series (length %d):\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d\n", fib_series[i]);
    }
}

    // for (int i = 1; i <= n-2; i++){
    //     c = a+b;
    //     printf("%d\n", c);
    //     a = b;
    //     b = c;
    // }
