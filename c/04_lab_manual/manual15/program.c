/* student_rec.c  — save one student’s details in student.rec */
#include <stdio.h>
#include <string.h>

#define FLUSHNL(s)  (s[strcspn(s, "\n")] = '\0')

int main(void)
{
    char name[50];
    char roll[10];
    char batch[10];
    char department[30];

    FILE *fp = fopen("student.rec", "w");
    if (!fp) {
        perror("student.rec");
        return 1;
    }

    puts("Name: Muhammad Ahsaan Abbasi");
    puts("Student ID: CSC-25S-013");
    puts("Section: BSCS-1A\n");

    printf("Enter student name: ");
    fgets(name, sizeof name, stdin);
    FLUSHNL(name);

    printf("Enter roll number: ");
    fgets(roll, sizeof roll, stdin);
    FLUSHNL(roll);

    printf("Enter batch: ");
    fgets(batch, sizeof batch, stdin);
    FLUSHNL(batch);

    printf("Enter department: ");
    fgets(department, sizeof department, stdin);
    FLUSHNL(department);

    fprintf(fp, "Name      : %s\n", name);
    fprintf(fp, "Roll No   : %s\n", roll);
    fprintf(fp, "Batch     : %s\n", batch);
    fprintf(fp, "Department: %s\n", department);
    fclose(fp);

    puts("\nStudent information saved to student.rec");
    return 0;
}
