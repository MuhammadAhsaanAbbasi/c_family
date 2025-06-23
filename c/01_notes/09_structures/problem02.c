#include<stdio.h>

struct vector{
    int i;
    int j;
};


struct vector sumVector(struct vector v1, struct vector v2){
    struct vector v3 = {v1.i + v2.i, v1.j + v2.j};

    return v3;
}


void main(){
    struct vector v1={2, 7}, v2={5, 8}, v3;
    printf("Enter the value of i and j\n");
    scanf("%d %d", &v1.i, &v1.j);
    printf("The value of i and j is %d and %d\n", v1.i, v1.j);
    v3=sumVector(v1, v2);

    printf("The Sum of value of i and j of v1 and v2 is %d and %d\n", v3.i, v3.j);
}