// 9. Write a structure capable of storing date. Write a function to compare those
// dates
#include<stdio.h>

struct date{
    int day;
    int month;
    int year;
};


int compare(struct date d1, struct date d2){
    if(d1.year == d2.year && d1.month == d2.month && d1.day == d2.day){
        return 0;
    }else if (d1.year < d2.year)
    {
        /* code */
        return 1;
    }
    else if (d1.year > d2.year)
    {
        /* code */
        return -1;
    }
    else if (d1.month < d2.month)
    {
        /* code */
        return 1;
    }
    else if (d1.month > d2.month)
    {
        /* code */
        return -1;
    }
    else if (d1.day < d2.day)
    {
        /* code */
        return 1;
    }
    else if (d1.day > d2.day)
    {
        /* code */
        return -1;
    }
} 


void main(){
    struct date d1 = {23, 12, 2004};
    struct date d2 = {21, 10, 2004};
    int result = compare(d1, d2);
    if(result==0){
        printf("Dates are equal");
    }
    else if(result == 1){
        printf("Date 1 is greater than Date 2");
    }
    else{
        printf("Date 2 is greater than Date 1");
    }
}