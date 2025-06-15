// 11. Implement 10 using other types of loops

#include <stdio.h>

void main()
{
    int num, i=2;
    printf("Enter a number: ");
    scanf("%d", &num);
    int flag = 0;
    while (i < num)
    {
        /* code */
        if (num % i == 0)
        {
            flag = 1;
            break;
        }
        i++;
    }
    
    if (flag == 0)
    {
        printf("Prime");
    }
    else
    {
        printf("Not Prime");
    }
}