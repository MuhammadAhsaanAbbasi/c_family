// A do while loop is executed:
// a. At least once.
// b. At least twice.
// c. At most once.

#include<stdio.h>

void main(){
    int n, i=0;
    printf("Enter a number: ");
    scanf("%d", &n);
    do
    {
        /* code */
        printf("%d\n", i);
        i++;
    } while (i <= 10);
    
}