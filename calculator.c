#include <stdio.h>


int main() {
    int choice;
    float num1, num2, result;

    while (1) 
    { 
        printf("\n==== Menu ====\n");
        printf("1. Add\n");
        printf("2. Subtract\n");
        printf("3. Multiply\n");           //Gives the user option to choose from
        printf("4. Divide\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 5)                   // breaks the loop
        {
            printf("Exiting the calculator. Goodbye!\n"); 
            break;
        }

        if (choice >= 1 && choice <= 4)    //gets two numbers 
        {
            printf("Enter first number: ");
            scanf("%f", &num1);
            printf("Enter second number: ");
            scanf("%f", &num2);
        }

        switch (choice) 
        {
            case 1:
                result = num1 + num2;      //adds the numbers
                printf("Result: %.2f + %.2f = %.2f\n", num1, num2, result);    
                break;

            case 2:                         
                result = num1 - num2;      //subtracts the numbers
                printf("Result: %.2f - %.2f = %.2f\n", num1, num2, result);
                break;

            case 3:
                result = num1 * num2;      //multiplies the numbers
                printf("Result: %.2f * %.2f = %.2f\n", num1, num2, result);
                break;

            case 4:
                if (num2 != 0)             //checks for zero
                {
                    result = num1 / num2;  //divided the numbers
                    printf("Result: %.2f / %.2f = %.2f\n", num1, num2, result);
                } else 
                {
                    printf("Error: Division by zero is not allowed.\n");
                }
                break;

            default:                       //insures the user inputs integer
                printf("Invalid choice. Please select a number between 1 and 5.\n");
        }
    }

    return 0;
}
