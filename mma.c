// Maxmimum, Minimum, Average

#include <stdio.h>
#include <string.h>

int main()
{    
    int students;
    printf("Enter number of students: ");
    scanf("%d", &students);

    int n;
    int a[students];
    printf("Enter marks: ");
    for(int i = 0; i <= sizeof(students); i++)
    {
        printf("Enter the marks for subjects for student %d: ", i+1);
        scanf("%d", &a[i]);
        // printf("%i\n",a[i]);
    }
    
    int *max=0;
    for (int i = 0; i <= sizeof(a); i++)
    {
        max = a[0];
        if (max > a[i+1])
        {
            continue;
        }
        else
        {
            max = a[i];
        }
    }
    printf("%i",max);
    
}
