// Grade Converter
// Given a numeric score (0–100), print a letter grade:
// 90+ → A
// 80–89 → B
// 70–79 → C
// below 70 → F

#include<stdio.h>

void main(){
    int score;
    char grade;

    printf("Enter Your Score:");
    scanf("%d", &score);

    if (score >= 90){
        grade = 'A';
    }
    else if (score >= 80 && score <= 89){
        grade = 'B';
    }
    else if (score >= 70 && score <= 79){
        grade = 'C';
    }
    else{
        grade = 'F';
    }

    printf("Depending on Your Score %d, Your Grade is %c", score, grade);
}