#include <stdio.h>

int main() {
    int marks[7];
    int total = 0;
    int failed = 0;
    
    printf("Enter marks for 7 subjects:\n");

    for (int i = 0; i < 7; i++) {
        printf("Subject %d: ", i + 1);
        scanf("%d", &marks[i]);

        if (marks[i] < 35) {
            failed = 1;
        }

        total += marks[i];
    }

    if (failed == 1) {
        printf("Result: Fail (one or more subjects below 35)\n");
    } else {
        float percentage = total / 7.0;

        printf("Total: %d\n", total);
        printf("Percentage: %.2f%%\n", percentage);

        if (percentage >= 60) {
            printf("Division: First\n");
        } else if (percentage >= 50) {
            printf("Division: Second\n");
        } else if (percentage >= 35) {
            printf("Division: Third\n");
        } else {
            printf("Result: Fail (percentage below 35)\n");
        }
    }

    return 0;
}