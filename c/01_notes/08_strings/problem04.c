#include<stdio.h>
#include <string.h>

int mystrlen(char *str){
    int len = 0;
    while (*str != '\0'){
        len++;
        str++;
    }
    return len;
}

char* SliceStr(char str[], int m, int n){
    char *ptr = &str[m];
    char *ptr2 = &str[n];

    str = ptr;

    str[n] = '\0';

    return str;
}

void main(){
    char name[11] = "HHijabieee";
    printf("Your Name is %s.",name);
    printf("\nYour Name Length is %d.", StrLen(name));
    printf("\nYour Name is %s.", SliceStr(name, 1, 7));
}