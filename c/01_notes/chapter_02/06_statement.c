#include <stdio.h>

void main() {
    char choice;
    int v1, v2;
    
    printf("Enter Value 1:");
    scanf("%d", &v1);
    scanf("%d", &v2);
    // v1=7;
    // v2=5;
    choice='1';

    if(choice == '1'){
        goto a;
    }
    else if (choice == '2')
    {
        /* code */
        goto b;
    }
    else {
        goto down;
    }
    

    a:
    printf("Hello World %d", v1*v2);

    b:
    printf("B Hello World %d", v2*v1);

    down:
    printf("Go to your hOme");
}