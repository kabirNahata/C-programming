#include <stdio.h>
#include <string.h>

union medicine{
    char name[20];
    int price;
}meds;

void main()
{
    strcpy(meds.name, "paracetamol");
    

    meds.price = 500000;
    printf("%i\n", meds.price);
    printf("%sh\n", meds.name);
}