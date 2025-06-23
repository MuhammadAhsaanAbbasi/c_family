#include<stdio.h>
#include <string.h>


int StrLen(char *str){
    int len = 0;
    while (*str != '\0'){
        len++;
        str++;
    }
    return len;
}

void main(){
    char name[8] = "Hijabie";
    printf("Your Name is %s.",name);
    printf("\nYour Name Length is %d.", StrLen(name));
}