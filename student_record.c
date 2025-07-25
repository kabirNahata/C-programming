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
void addStudent();
void viewStudents();
void searchStudent();
void deleteStudent();
void menu();

int main() 
{
    menu(); // call the main menu function
    return 0;
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
                // Using goto to return to menu (not ideal in real projects, but shown here for learning)
                goto end_of_loop;
        };

    } while (choice != 5); // do-while loop to repeat menu
}

// Function to add a student record
void addStudent() 
{
    int space = sizeof(students);
    if (space >= 100) 
    {
        printf("Cannot add more students. Maximum limit reached.\n");
        return;
    }

    printf("\n--- Add Student ---\n");
    printf("Enter Roll Number: ");
    scanf("%d", &students[space].roll);
    getchar(); // clear newline from buffer

    printf("Enter Name: ");
    fgets(students[space].name, sizeof(students[space].name), stdin);
    students[space].name[strcspn(students[space].name, "\n")] = 0; // remove newline

    printf("Enter Course: ");
    fgets(students[space].course, sizeof(students[space].course), stdin);
    students[space].course[strcspn(students[space].course, "\n")] = 0; // remove newline
    printf("Student added successfully.\n");
}

// Function to view all student records
void viewStudents() {
    printf("\n--- Student List ---\n");
    int no_student = sizeof(students) ;
    if (no_student == 0) {
        printf("No student records available.\n");
        return;
    }

    for (int i = 0; i < no_student; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].roll);
        printf("Name   : %s\n", students[i].name);
        printf("Course : %s\n", students[i].course);
    }
}

// Function to search a student by roll number
void searchStudent() 
{
    int student_list = sizeof(students);
    int roll;
    int found = 0;

    printf("\nEnter Roll Number to search: ");
    scanf("%d", &roll);

    for (int i = 0; i < student_list; i++) {
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
void deleteStudent() 
{
    int remaining_student = sizeof(students);
    int roll;
    printf("\nEnter Roll Number to delete: ");
    scanf("%d", &roll);

    int found = 0;
    for (int i = 0; i < remaining_student; i++) {
        if (students[i].roll == roll) {
            // Shift all remaining students left by 1
            for (int j = i; j < remaining_student - 1; j++) {
                students[j] = students[j + 1];
            }
            found = 1;
            printf("Student with Roll No %d deleted.\n", roll);
            break;
        }
    }

    if (!found) {
        printf("Student not found.\n");
    }
}
