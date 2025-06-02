#include <stdio.h>
#include <conio.h>
struct student
{
    char name[50];
    int roll;
};
void display(struct student s)
{
    printf("\n--- Student Information ---\n");
    printf("Name : %s\n", s.name);
    printf("Roll : %d\n", s.roll);
}
void main()
{
    struct student s;

    // clrscr();
    printf("\nName: Muhammad Ahsaan Abbasi \nSTUDENT ID: CSC-25S-013 \nSECTION: BSCS-1A\n\n");
    printf("Enter student name: ");
    gets(s.name);
    printf("Enter roll number: ");
    scanf("%d", &s.roll);
    display(s);
    // getch();
}
