#include<stdio.h>

int mystrlen(char *str){
    int len = 0;
    while (*str != '\0'){
        len++;
        str++;
    }
    return len;
}

void main(){
    char info[20] = "J!Mpwf!zpv!Ijkbcjf";
    
    for(int i=0; i<mystrlen(info); i++){
        info[i] = info[i] - 1;
    }
    printf("\n");
    printf("%s", info);
}