#include <stdio.h>
#include <stdlib.h>

// Define a Matrix structure
typedef struct {
    int rows;
    int cols;
    int **data;
} Matrix;

// Allocate memory for a matrix
Matrix createMatrix(int rows, int cols) {
    Matrix m;
    m.rows = rows;
    m.cols = cols;
    m.data = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
        m.data[i] = (int *)malloc(cols * sizeof(int));
    return m;
}

// Free the memory
void freeMatrix(Matrix *m) {
    for (int i = 0; i < m->rows; i++)
        free(m->data[i]);
    free(m->data);
}

// Input matrix from terminal
void inputMatrix(Matrix *m) {
    printf("Enter elements (%dx%d):\n", m->rows, m->cols);
    for (int i = 0; i < m->rows; i++)
        for (int j = 0; j < m->cols; j++)
            scanf("%d", &m->data[i][j]);
}

// Display matrix
void displayMatrix(Matrix *m) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++)
            printf("%d\t", m->data[i][j]);
        printf("\n");
    }
}

// Add matrices
Matrix addMatrix(Matrix *a, Matrix *b) {
    Matrix result = createMatrix(a->rows, a->cols);
    for (int i = 0; i < a->rows; i++)
        for (int j = 0; j < a->cols; j++)
            result.data[i][j] = a->data[i][j] + b->data[i][j];
    return result;
}

// Subtract matrices
Matrix subtractMatrix(Matrix *a, Matrix *b) {
    Matrix result = createMatrix(a->rows, a->cols);
    for (int i = 0; i < a->rows; i++)
        for (int j = 0; j < a->cols; j++)
            result.data[i][j] = a->data[i][j] - b->data[i][j];
    return result;
}

// Multiply matrices
Matrix multiplyMatrix(Matrix *a, Matrix *b) {
    Matrix result = createMatrix(a->rows, b->cols);
    for (int i = 0; i < a->rows; i++)
        for (int j = 0; j < b->cols; j++) {
            result.data[i][j] = 0;
            for (int k = 0; k < a->cols; k++)
                result.data[i][j] += a->data[i][k] * b->data[k][j];
        }
    return result;
}

// Log matrix to file
void logMatrix(FILE *file, const char *title, Matrix *m) {
    fprintf(file, "%s (%dx%d):\n", title, m->rows, m->cols);
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++)
            fprintf(file, "%d ", m->data[i][j]);
        fprintf(file, "\n");
    }
}

int main() {
    Matrix A, B, Result;
    int r1, c1, r2, c2;
    int choice;

    // Clear previous log
    FILE *clearLog = fopen("matrix_log.txt", "w");
    if (clearLog) fclose(clearLog);

    printf("Matrix Operations with Logging\n");
    printf("Enter rows and columns for first matrix: ");
    scanf("%d%d", &r1, &c1);
    A = createMatrix(r1, c1);
    inputMatrix(&A);

    printf("Enter rows and columns for second matrix: ");
    scanf("%d%d", &r2, &c2);
    B = createMatrix(r2, c2);
    inputMatrix(&B);

    do {
        printf("\nChoose Operation:\n");
        printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (A.rows == B.rows && A.cols == B.cols) {
                    Result = addMatrix(&A, &B);
                    printf("Addition Result:\n");
                    displayMatrix(&Result);

                    FILE *logAdd = fopen("matrix_log.txt", "a");
                    if (logAdd) {
                        fprintf(logAdd, "\n==== ADDITION ====\n");
                        logMatrix(logAdd, "Matrix A", &A);
                        logMatrix(logAdd, "Matrix B", &B);
                        logMatrix(logAdd, "Result", &Result);
                        fclose(logAdd);
                    }

                    freeMatrix(&Result);
                } else {
                    printf("Addition not possible (size mismatch).\n");
                }
                break;

            case 2:
                if (A.rows == B.rows && A.cols == B.cols) {
                    Result = subtractMatrix(&A, &B);
                    printf("Subtraction Result:\n");
                    displayMatrix(&Result);

                    FILE *logSub = fopen("matrix_log.txt", "a");
                    if (logSub) {
                        fprintf(logSub, "\n==== SUBTRACTION ====\n");
                        logMatrix(logSub, "Matrix A", &A);
                        logMatrix(logSub, "Matrix B", &B);
                        logMatrix(logSub, "Result", &Result);
                        fclose(logSub);
                    }

                    freeMatrix(&Result);
                } else {
                    printf("Subtraction not possible (size mismatch).\n");
                }
                break;

            case 3:
                if (A.cols == B.rows) {
                    Result = multiplyMatrix(&A, &B);
                    printf("Multiplication Result:\n");
                    displayMatrix(&Result);

                    FILE *logMul = fopen("matrix_log.txt", "a");
                    if (logMul) {
                        fprintf(logMul, "\n==== MULTIPLICATION ====\n");
                        logMatrix(logMul, "Matrix A", &A);
                        logMatrix(logMul, "Matrix B", &B);
                        logMatrix(logMul, "Result", &Result);
                        fclose(logMul);
                    }

                    freeMatrix(&Result);
                } else {
                    printf("Multiplication not possible (A.cols != B.rows).\n");
                }
                break;

            case 4:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);

    freeMatrix(&A);
    freeMatrix(&B);

    return 0;
}
