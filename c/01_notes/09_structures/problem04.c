#include <stdio.h>
#include <string.h> // For removing newline after fgets

struct employee {
    int id;
    char name[50]; // make it a bit bigger
    float salary;
};

int main() {
    struct employee e1;
    struct employee *ptr = &e1;

    printf("Enter employee id : ");
    scanf("%d", &ptr->id);
    getchar(); // <-- This clears the leftover newline

    printf("Enter employee name : ");
    fgets(ptr->name, sizeof(ptr->name), stdin);

    // Remove trailing newline from fgets
    ptr->name[strcspn(ptr->name, "\n")] = 0;

    printf("Enter employee salary : ");
    scanf("%f", &ptr->salary);

    printf("Employee id : %d\n", ptr->id);
    printf("Employee name : %s\n", ptr->name);
    printf("Employee salary : %.2f\n", ptr->salary);

    return 0;
}
