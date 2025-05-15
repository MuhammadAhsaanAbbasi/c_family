// Pair combinations
// Given arrays A = [1,2,3] and B = ['a','b'], use nested loops to print all pairs:

#include<stdio.h>
// #include <dos.h>
#include <string.h>

void main(){
    char a[3] = {'a', 'b', 'c'};
    int b[3] = {1, 2, 3};
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("(%c, %d)\n", a[i], b[j]);
        };
    }
}