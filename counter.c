#include <stdio.h>
#include <string.h>

// Define a structure to store student data
struct Student {
    int roll;
    char name[50];
    char course[30];
};

// Declare global variables
struct Student students[100]; // array of student records

// Function prototypes
void initializeStudents();
void addStudent();
void viewStudents();
void searchStudent();
void deleteStudent();
void menu();

int main() 
{
    initializeStudents();  // Initialize all roll numbers to -1 (sentinel)
    menu();                // Call the main menu
    return 0;
}

// Initialize all student roll numbers to -1 (sentinel)
void initializeStudents() {
    for (int i = 0; i < 100; i++) {
        students[i].roll = -1;
    }
}

// Menu function with do-while and switch-case
void menu() 
{
    int choice;
    
    do {
        end_of_loop:
        printf("\n--- Student Record Management System ---\n");
        printf("1. Add Student\n");
        printf("2. View All Students\n");
        printf("3. Search Student by Roll Number\n");
        printf("4. Delete Student by Roll Number\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                viewStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                deleteStudent();
                break;
            case 5:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                goto end_of_loop;
        };

    } while (choice != 5);
}

// Function to add a student record
void addStudent() 
{
    int index = -1;

    // Find the first available (empty) slot
    for (int i = 0; i < 100; i++) 
    {
        if (students[i].roll == -1) 
        {
            index = i;
            break;
        }
    }

    if (index == -1) 
    {
        printf("Cannot add more students. Maximum limit reached.\n");
        return;
    }

    printf("\n--- Add Student ---\n");
    printf("Enter Roll Number: ");
    scanf("%d", &students[index].roll);
    getchar(); // clear newline from buffer

    printf("Enter Name: ");
    fgets(students[index].name, sizeof(students[index].name), stdin);
    students[index].name[strcspn(students[index].name, "\n")] = 0;

    printf("Enter Course: ");
    fgets(students[index].course, sizeof(students[index].course), stdin);
    students[index].course[strcspn(students[index].course, "\n")] = 0;

    printf("Student added successfully.\n");
}

// Function to view all student records
void viewStudents() {
    printf("\n--- Student List ---\n");
    int found = 0;

    for (int i = 0; i < 100; i++) {
        if (students[i].roll == -1) {
            break;
        }

        found = 1;
        printf("\nStudent %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].roll);
        printf("Name   : %s\n", students[i].name);
        printf("Course : %s\n", students[i].course);
    }

    if (!found) {
        printf("No student records available.\n");
    }
}

// Function to search a student by roll number
void searchStudent() 
{
    int roll;
    int found = 0;

    printf("\nEnter Roll Number to search: ");
    scanf("%d", &roll);

    for (int i = 0; i < 100 && students[i].roll != -1; i++) {
        if (students[i].roll == roll) {
            printf("\nStudent Found:\n");
            printf("Roll No: %d\n", students[i].roll);
            printf("Name   : %s\n", students[i].name);
            printf("Course : %s\n", students[i].course);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student with Roll No %d not found.\n", roll);
    }
}

// Function to delete a student by roll number
// void deleteStudent() 
// {
//     int roll;
//     printf("\nEnter Roll Number to delete: ");
//     scanf("%d", &roll);

//     int found = 0;
//     for (int i = 0; i < 100 && students[i].roll != -1; i++) {
//         if (students[i].roll == roll) {
//             // Shift remaining records left
//             for (int j = i; j < 99 && students[j + 1].roll != -1; j++) {
//                 students[j] = students[j + 1];
//             }
//             // Clear the last used record
//             students[99].roll = -1;
//             strcpy(students[99].name, "");
//             strcpy(students[99].course, "");

//             found = 1;
//             printf("Student with Roll No %d deleted.\n", roll);
//             break;
//         }
//     }

//     if (!found) {
//         printf("Student not found.\n");
//     }
// }


void deleteStudent() //delete function with value shifting and checking for the last value deletion
{
    int roll;
    printf("\nEnter Roll Number to delete: ");
    scanf("%d", &roll);

    int found = 0;
    for (int i = 0; i < 100 && students[i].roll != -1; i++) {
        if (students[i].roll == roll) {
            found = 1;

            // Check if the next student is valid
            if (students[i + 1].roll != -1) {
                // Shift students left from i to the last valid entry
                for (int j = i; j < 99 && students[j + 1].roll != -1; j++) {
                    students[j] = students[j + 1];
                }

                // Clear the last valid slot after shifting
                students[99].roll = -1;
                strcpy(students[99].name, "");
                strcpy(students[99].course, "");
            } else {
                // It's the last student, just clear it
                students[i].roll = -1;
                strcpy(students[i].name, "");
                strcpy(students[i].course, "");
            }

            printf("Student with Roll No %d deleted.\n", roll);
            break;
        }
    }

    if (!found) {
        printf("Student with Roll No %d not found.\n", roll);
    }
}

