// Take name and salary of two employees as input from the user and write them to
// a text file in the following format:
// i. Name1, 3300
// ii. Name2, 7700


#include<stdio.h>

void main(){
    FILE *fptr;
    fptr = fopen("emp.txt","a");

    char name[2][20];
    int salary[2];

    for(int i=0;i<2;i++){
        printf("Enter the name and salary of employee %d: ",i+1);
        scanf("%s %d",name[i],&salary[i]);
    }

    for(int i=0;i<2;i++){
        fprintf(fptr,"%s, %d\n",name[i],salary[i]);
    }

    fclose(fptr);
}