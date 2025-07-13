#include <stdio.h>

int main() {
    int number, original, digitCount = 0, sum = 0, reversed = 0;

    // Input
    printf("Enter a positive integer: ");
    scanf("%d", &number);

    // Store original for output
    original = number;

    // Check for valid input
    if (number <= 0) {
        printf("Please enter a positive integer.\n");
        return 1;
    }

    // Digit processing
    while (number > 0) {
        int digit = number % 10;     // Get last digit
        sum += digit;                // Add to sum
        reversed = reversed * 10 + digit; // Build reversed number
        digitCount++;                // Increment digit count
        number /= 10;                // Remove last digit
    }

    // Output
    printf("Input: %d\n", original);
    printf("Total Digits: %d\n", digitCount);
    printf("Sum of Digits: %d\n", sum);
    printf("Reversed Number: %d\n", reversed);

    return 0;
}
