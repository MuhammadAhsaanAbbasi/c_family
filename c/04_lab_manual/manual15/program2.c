#include <stdio.h>
#include <conio.h>

void main()
{
    int status;
    // clrscr();
    printf("\n Name: Muhammad Ahsaan Abbasi\n STUDENT ID: CSC-25S-013\n SECTION: BSCS-1A\n\n");
    status = remove("student.rec");
    if (status == 0)
        printf("File 'student.rec' deleted successfully.");
    else
        printf("Unable to delete the file. It may not exist.");
    // getch();
}
