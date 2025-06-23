// 5. Create an array of multiplication table of 7 upto 10 (7 x 10 = 70). Use realloc to
// make it store 15 number (from 7 x 1 to 7 x 15).

#include<stdio.h>
#include<stdlib.h>

void main(){
    int *ptr;
    ptr = (int *)malloc(10*sizeof(int));
    for(int i=0;i<10;i++){
        ptr[i] = 7*(i+1);
    }
    printf("Table of 7 from 1 to 10\n");
    for (int i = 0; i < 10; i++)
    {
        /* code */
        printf("7 x %d = %d\n", i+1, ptr[i]);
    }
    
    ptr = realloc(ptr,15*sizeof(int));
    for(int i=0;i<15;i++){
        ptr[i] = 7*(i+1);
    }
    printf("Table of 7 from 1 to 15\n");
    for (int i = 0; i < 15; i++)
    {
        /* code */
        printf("7 x %d = %d\n", i+1, ptr[i]);
    }
}