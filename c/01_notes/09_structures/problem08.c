// Create a structure representing a bank account of a customer. What fields did
// you use and why?

typedef struct {
    int accountNumber;
    char name[50];
    float balance;
} BankAccount;

#include<stdio.h>
#include<string.h>

void main(){
    BankAccount account;
    printf("Enter account number: ");
    scanf("%d", &account.accountNumber);
    getchar(); // <-- This clears the leftover newline

    printf("Enter name: ");
    fgets(account.name, sizeof(account.name), stdin);

    // Remove trailing newline from fgets
    account.name[strcspn(account.name, "\n")] = 0;
    printf("Enter balance: ");
    scanf("%.2f", &account.balance);
    printf("Account number: %d\n", account.accountNumber);
    printf("Name: %s\n", account.name);
    printf("Balance: %f\n", account.balance);
}