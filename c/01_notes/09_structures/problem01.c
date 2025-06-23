#include<stdio.h>

struct vector{
    int i;
    int j;
};


void main(){
    struct vector v1;
    printf("Enter the value of i and j\n");
    scanf("%d %d", &v1.i, &v1.j);
    
    printf("The value of i and j is %d and %d\n", v1.i, v1.j);
}