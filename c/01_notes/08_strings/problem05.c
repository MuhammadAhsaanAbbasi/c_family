#include<stdio.h>

int mystrlen(char *str){
    int len = 0;
    while (*str != '\0'){
        len++;
        str++;
    }
    return len;
}

void mystrcpy(char *dest, char *src){
    while (*src != '\0'){
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}


void main(){
    char name[10] = "Hijabie";
    char name2[10];
    mystrcpy(name2, name);
    printf("Your Name is %s.",name);
    printf("\nYour Copied Name is %s.", name2);
    printf("\nYour Name Length is %d.", mystrlen(name));
}