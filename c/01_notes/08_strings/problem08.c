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
    char c = '!';
    int count=0;
    
    for(int i=0; i<mystrlen(info); i++){
        if (info[i]==c)
        {
            /* code */
            count++;
        }
        
    }
    printf("\n");
    printf("%s", info);
    printf("\n");
    printf("The number of %c is %d", c, count);
}