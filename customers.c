// customers.c 
#include "customers.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void insert_data(Customers *customers) {
    strcpy(customers->name, "Name");
    strcpy(customers->email, "Email");
    customers->age = 18;
}

void remove_data(Customers *customers) {
    strcpy(customers->name, "");
    strcpy(customers->email, "");
    customers->age = 0;
}

void change_data(Customers *customers) {
    printf("Enter new name: ");
    scanf("%s", customers->name);
    printf("Enter new email: ");
    scanf("%s", customers->email);
    printf("Enter new age: ");
    scanf("%d", &customers->age);
}

void print_data(Customers customers) {
    printf("%s %s %d\n", customers.name, customers.email, customers.age);
}
