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
    int contains=0;
    
    for(int i=0; i<mystrlen(info); i++){
        if (info[i]==c)
        {
            /* code */
            contains+=1;
            break;
        }
        
    }
    printf("\n");
    printf("%s", info);
    printf("\n");
    if (contains)
    {
        /* code */
        printf("String contains %c", c);
    }
    else{
        printf("String does not contain %c", c);
    }
    
}