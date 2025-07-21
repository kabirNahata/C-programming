#include <stdio.h>

int main(){
    int length;

    printf("Enter the length");
    scanf("%i", &length);

    for (int i = length; i >= 1; i--){
        for (int j = 1; j <= i; j++){
            printf("%i", j);
        }printf("\n");
    }return 0;
}