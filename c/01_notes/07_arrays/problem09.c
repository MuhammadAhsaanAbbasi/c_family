// 9. Create a three–dimensional array and print the address of its elements in
// increasing order

#include<stdio.h>

void main(){
    int arr[2][3][4];

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            // printf("The address of arr[%d][%d] is %u\n",i,j,&arr[i][j]);
            for (int k = 0; k < 4; k++)
            {
                printf("The address of arr[%d][%d][%d] is %u\n",i,j,k,&arr[i][j][k]);
            }
            
        }
        
    }
    
}