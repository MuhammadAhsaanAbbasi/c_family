// Write a program to take string as an input from the user using %c and %s confirm
// that the strings are equal.

#include<stdio.h>

void main(){
    char name[8];
    
    for(int i=0;i<8;i++){
        scanf("%c",&name[i]);
        fflush(stdin);
    }
    name[8] = '\0';
    printf("Your Name is %s.",name);
}