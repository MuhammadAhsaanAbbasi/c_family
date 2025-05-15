#include <stdio.h>

void main() {
    // Declare pointers to char for storing string literals
    char *car_name;
    char *company;
    int rate, tax, total;
    
    printf("Welcome to Abbasi Showroom\n");
    printf("Select Your Car Number to See Details\n");
    printf("1. Cultus\n");
    printf("2. Civic\n");
    printf("3. Sportage\n");
    printf("4. Taft\n");

    int user_choice;
    scanf("%d", &user_choice);

    if (user_choice == 1) {
        car_name = "Cultus";
        company = "Honda";
        rate = 100000;
    }
    else if (user_choice == 2) {
        car_name = "Civic";
        company = "Honda";
        rate = 150000;
    }
    else if (user_choice == 3) {
        car_name = "Sportage";
        company = "Kia";
        rate = 200000;
    }
    else if (user_choice == 4) {
        car_name = "Taft";
        company = "Kia";
        rate = 250000;
    }
    else {
        printf("Invalid choice\n");
    }

    // Calculate tax and total (example calculation)
    tax = rate * 20 / 100;
    total = rate + tax;
    
    printf("Car Name: %s\n", car_name);
    printf("Company: %s\n", company);
    printf("Rate: %d\n", rate);
    printf("Tax: %d\n", tax);
    printf("Total: %d\n", total);
    
}
