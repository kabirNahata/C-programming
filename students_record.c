#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

struct Student
{
    int roll;
    char name[50];
    char course[30];
};

void initializeStudents(struct Student students[], int size);
void addStudent(struct Student students[], int size);
void viewStudents(const struct Student students[], int size);
void searchStudent(const struct Student students[], int size);
void deleteStudent(struct Student students[], int size);
void menu(struct Student students[], int size);

int main()
{
    struct Student students[MAX_STUDENTS];
    initializeStudents(students, MAX_STUDENTS);
    menu(students, MAX_STUDENTS);
    return 0;
}

void initializeStudents(struct Student students[], int size)
{
    for (int i = 0; i < size; i++)
    {
        students[i].roll = -1;
    }
}

void menu(struct Student students[], int size)
{
    int choice;

    do
    {
        printf("\n--- Student Record Management System ---\n");
        printf("1. Add Student\n");
        printf("2. View All Students\n");
        printf("3. Search Student by Roll Number\n");
        printf("4. Delete Student by Roll Number\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            choice = 0; // Set to a non-exit value to continue loop
            continue;
        }
        getchar(); // Consume the newline character left by scanf

        switch (choice)
        {
            case 1:
                addStudent(students, size);
                break;
            
            case 2:
                viewStudents(students, size);
                break;
               
            case 3:
                searchStudent(students, size);
                break;

            case 4:
                deleteStudent(students, size);
                break;

            case 5:
                printf("Exiting program. Goodbye!\n");
                break;
            
            default:
                printf("Invalid choice. Try again.\n");
        };
    } while (choice != 5);
}

void addStudent(struct Student students[], int size)
{
    int index = -1;
    int roll;

    for (int i = 0; i < size; i++)
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
    
    if (scanf("%d", &roll) != 1) {
        printf("Invalid input. Please enter a number for the Roll Number.\n");
        while (getchar() != '\n'); // Clear input buffer
        return;
    }
    getchar(); // Consume the newline character left by scanf

    for (int i = 0; i < size; i++) {
        if (students[i].roll == roll) {
            printf("Student with Roll No %d already exists.\n", roll);
            return;
        }
    }

    students[index].roll = roll;

    printf("Enter Name: ");
    fgets(students[index].name, sizeof(students[index].name), stdin);
    students[index].name[strcspn(students[index].name, "\n")] = 0;

    printf("Enter Course: ");
    fgets(students[index].course, sizeof(students[index].course), stdin);
    students[index].course[strcspn(students[index].course, "\n")] = 0;

    printf("Student added successfully.\n");
}

void viewStudents(const struct Student students[], int size)
{
    printf("\n--- Student List ---\n");
    int found = 0;

    for (int i = 0; i < size; i++)
    {
        if (students[i].roll != -1)
        {
            found = 1;
            printf("\nStudent %d:\n", i + 1);
            printf("Roll No: %d\n", students[i].roll);
            printf("Name   : %s\n", students[i].name);
            printf("Course : %s\n", students[i].course);
        }
    }

    if (!found)
    {
        printf("No student records available.\n");
    }
}

void searchStudent(const struct Student students[], int size)
{
    int roll;
    int found = 0;

    printf("\nEnter Roll Number to search: ");
    if (scanf("%d", &roll) != 1) {
        printf("Invalid input. Please enter a number for the Roll Number.\n");
        while (getchar() != '\n'); // Clear input buffer
        return;
    }
    getchar(); // Consume the newline character

    for (int i = 0; i < size; i++)
    {
        if (students[i].roll == roll)
        {
            printf("\nStudent Found:\n");
            printf("Roll No: %d\n", students[i].roll);
            printf("Name   : %s\n", students[i].name);
            printf("Course : %s\n", students[i].course);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Student with Roll No %d not found.\n", roll);
    }
}

void deleteStudent(struct Student students[], int size)
{
    int roll;
    printf("\nEnter Roll to delete: ");
    if (scanf("%d", &roll) != 1) {
        printf("Invalid input. Please enter a number for the Roll Number.\n");
        while (getchar() != '\n'); // Clear input buffer
        return;
    }
    getchar(); // Consume the newline character

    int found_index = -1;
    for (int i = 0; i < size; i++)
    {
        if (students[i].roll == roll)
        {
            found_index = i;
            break;
        }
    }

    if (found_index != -1)
    {
        for (int i = found_index; i < size - 1; i++) 
        {
            students[i] = students[i + 1];
        }

        students[size - 1].roll = -1;
        strcpy(students[size - 1].name, "");
        strcpy(students[size - 1].course, "");

        printf("Student with Roll No %d deleted.\n", roll);
    }
    else 
    {
        printf("Student with Roll No %d not found.\n", roll);
    }
}