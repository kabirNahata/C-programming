#include <stdio.h>
#include <math.h>

int main(){
    int num, original_num, remainder, result, n = 0;

    printf("Enter any number: ");
    scanf("%i", &num);

    original_num = num;

    int temp_num = num;
    while (temp_num != 0){
        temp_num /= 10;
        ++n;
    }

    temp_num = original_num;

    while (temp_num != 0){
        remainder = temp_num % 10;
        result += pow(remainder, n);
        temp_num /= 10;
    }
    
    if (result == original_num){
        printf("%d is an Armstrong number.\n", original_num);
    } 
    else{
        printf("%d is not an Armstrong number.\n", original_num);
    }
}