// 2. Write a program to generate multiplication table of a given number in text
// format. Make sure that the file is readable and well formatted.


#include<stdio.h>

void main(){
    FILE *fp;
    int n;
    printf("Enter a number : ");
    scanf("%d",&n);
    fp = fopen("table.txt","w");
    for(int i=1;i<=10;i++){
        fprintf(fp,"%d x %d = %d\n",n,i,n*i);
    }
    fclose(fp);
}