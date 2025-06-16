// 5. Write a program to modify a file containing an integer to double its value.

#include<stdio.h>

void main(){
    FILE *fp;
    int num;
    fp = fopen("file.txt","r+");
    fscanf(fp,"%d",&num);
    fseek(fp,0,SEEK_SET);
    fprintf(fp,"%d",num*2);
}