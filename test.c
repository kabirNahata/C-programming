#include <stdio.h>
#include <string.h>

struct Student {
    int roll;
    char name[50];
    char course[30];
};

// Function prototypes
int addStudent(struct Student students[], int count);
void viewStudents(struct Student students[], int count);
void searchStudent(struct Student students[], int count);
int deleteStudent(struct Student students[], int count);
void menu();

int main() {
    struct Student students[100];
    int count = 0;
    int choice;

    do {
        printf("\n--- Student Record Management System ---\n");
        printf("1. Add Student\n");
        printf("2. View All Students\n");
        printf("3. Search Student by Roll Number\n");
        printf("4. Delete Student by Roll Number\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline

        switch (choice) {
            case 1:
                count = addStudent(students, count);
                break;
            case 2:
                viewStudents(students, count);
                break;
            case 3:
                searchStudent(students, count);
                break;
            case 4:
                count = deleteStudent(students, count);
                break;
            case 5:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (choice != 5);

    return 0;
}

int addStudent(struct Student students[], int count) 
{
    if (count >= 100) {
        printf("Cannot add more students. Maximum limit reached.\n");
        return count;
    }

    printf("\n--- Add Student ---\n");
    printf("Enter Roll Number: ");
    scanf("%d", &students[count].roll);
    getchar(); // clear newline

    printf("Enter Name: ");
    fgets(students[count].name, sizeof(students[count].name), stdin);
    students[count].name[strcspn(students[count].name, "\n")] = 0;

    printf("Enter Course: ");
    fgets(students[count].course, sizeof(students[count].course), stdin);
    students[count].course[strcspn(students[count].course, "\n")] = 0;

    printf("Student added successfully.\n");
    return count + 1;
}

void viewStudents(struct Student students[], int count) 
{
    printf("\n--- Student List ---\n");

    if (count == 0) {
        printf("No student records available.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].roll);
        printf("Name   : %s\n", students[i].name);
        printf("Course : %s\n", students[i].course);
    }
}

void searchStudent(struct Student students[], int count) 
{
    int roll;
    int found = 0;

    printf("\nEnter Roll Number to search: ");
    scanf("%d", &roll);

    for (int i = 0; i < count; i++) {
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

int deleteStudent(struct Student students[], int count) 
{
    int roll, found = 0;
    printf("\nEnter Roll Number to delete: ");
    scanf("%d", &roll);

    for (int i = 0; i < count; i++) {
        if (students[i].roll == roll) {
            for (int j = i; j < count - 1; j++) {
                students[j] = students[j + 1];
            }
            printf("Student with Roll No %d deleted.\n", roll);
            found = 1;
            return count - 1;
        }
    }

    if (!found) {
        printf("Student not found.\n");
    }

    return count;
}
