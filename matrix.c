#include <stdio.h>

#define MAX 10  // max rows and cols

void inputMatrix(int matrix[MAX][MAX], int row, int col) 
{
    printf("Enter elements (%dx%d):\n", row, col);
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            scanf("%d", &matrix[i][j]);
}

void displayMatrix(int matrix[MAX][MAX], int row, int col) {
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++)
            printf("%d\t", matrix[i][j]);
        printf("\n");
    }
}

void addMatrix(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int row, int col) {
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            result[i][j] = a[i][j] + b[i][j];
}

void subtractMatrix(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int row, int col) {
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            result[i][j] = a[i][j] - b[i][j];
}

void multiplyMatrix(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int row1, int col1, int col2) {
    for(int i = 0; i < row1; i++)
        for(int j = 0; j < col2; j++) {
            result[i][j] = 0;
            for(int k = 0; k < col1; k++)
                result[i][j] += a[i][k] * b[k][j];
        }
}

int main() {
    int A[MAX][MAX], B[MAX][MAX], Result[MAX][MAX];
    int r1, c1, r2, c2;
    int choice;

    printf("Matrix Operations in C\n");
    printf("Enter rows and columns for first matrix: ");
    scanf("%d%d", &r1, &c1);
    inputMatrix(A, r1, c1);

    printf("Enter rows and columns for second matrix: ");
    scanf("%d%d", &r2, &c2);
    inputMatrix(B, r2, c2);

    printf("\nChoose Operation:\n1. Addition\n2. Subtraction\n3. Multiplication\nEnter choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            if(r1 == r2 && c1 == c2) {
                addMatrix(A, B, Result, r1, c1);
                printf("Addition Result:\n");
                displayMatrix(Result, r1, c1);
            } else {
                printf("Addition not possible (size mismatch).\n");
            }
            break;
        case 2:
            if(r1 == r2 && c1 == c2) {
                subtractMatrix(A, B, Result, r1, c1);
                printf("Subtraction Result:\n");
                displayMatrix(Result, r1, c1);
            } else {
                printf("Subtraction not possible (size mismatch).\n");
            }
            break;
        case 3:
            if(c1 == r2) {
                multiplyMatrix(A, B, Result, r1, c1, c2);
                printf("Multiplication Result:\n");
                displayMatrix(Result, r1, c2);
            } else {
                printf("Multiplication not possible (column of A != row of B).\n");
            }
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}
