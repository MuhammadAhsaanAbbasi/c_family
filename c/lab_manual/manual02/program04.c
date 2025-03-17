#include<stdio.h>

void main(){
    int even_number, odd_number;
    // printf("Enter the number of Table:");
    // scanf("%d", &num);
    // int max=100;
    even_number=0;
    odd_number=0;
    for (int i = 1; i <= 100; i++)
    {
        /* code */
        printf("%d\n", i);
        if(i % 2 == 0) {
            // printf("\nNumber is Even: %d", i);
            even_number++;
        } else if (i % 2 != 0)
        {
        //    printf("\nNumber is Odd: %d", i);
           odd_number++;
       }

       
    };
    printf("Even Numbers: %d\n", even_number);
    printf("Odd Numbers: %d", odd_number);
    
}