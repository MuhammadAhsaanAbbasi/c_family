#include<stdio.h>
#include <conio.h>

void main(){
    int a;
    for (a=1; a<=10; a++){
        printf("%d\n", a*a*a);
        if (a==5){
            break;
        }
    }
}