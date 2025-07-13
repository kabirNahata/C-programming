#include <stdio.h>
#include <stdlib.h>  // for exit()

// Structure of variables
struct student_record_system {
    char name[50];
    int age;
    float marks;
};

// Function to find the topper
struct student_record_system findTopper(struct student_record_system s[], int n) {
    int topper = 0;
    for (int i = 1; i < n; i++) {
        if (s[i].marks > s[topper].marks) {
            topper = i;
        }
    }
    return s[topper];
}

// Function to calculate average marks
float calculateAverage(struct student_record_system s[], int n) {
    float sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += s[i].marks;
    }
    return sum / n;
}

int main() {
    FILE *fptr;
    fptr = fopen("C:\\Users\\Dell\\Desktop\\cprogram_students.txt", "w");
    if (fptr == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    struct student_record_system students[5];

    for (int i = 0; i < 5; i++) {
        printf("Enter name: ");
        scanf("%s", students[i].name);

        printf("Enter age: ");
        scanf("%d", &students[i].age);

        printf("Enter marks: ");
        scanf("%f", &students[i].marks);
    }

    for (int i = 0; i < 5; i++) 
    {
        printf(" ");
        printf("%d. %s is %d years old. He got %.2f marks\n",
                i + 1, students[i].name, students[i].age, students[i].marks);

        fprintf(fptr, "%d. %s is %d years old. He got %.2f marks\n",
                i + 1, students[i].name, students[i].age, students[i].marks);
    }

    struct student_record_system topper = findTopper(students, 5);
    printf("\nTopper:\nName: %s\nMarks: %.2f\n", topper.name, topper.marks);
    fprintf(fptr, "\nTopper:\nName: %s\nMarks: %.2f\n", topper.name, topper.marks);

    float average = calculateAverage(students, 5);
    printf("Average Marks of all students: %.2f\n", average);
    fprintf(fptr, "Average Marks of all students: %.2f\n", average);

    fclose(fptr);

    printf("Stored in file!");

    return 0;
}
