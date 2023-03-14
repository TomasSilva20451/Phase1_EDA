// customers.h 
#ifndef customers_h
#define customers_h

#include "electric_mobility_means.h"

typedef struct Customers {
    char name[50];
    char email[50];
    int age;
} Customers;

void insert_data(Customers *customers);
void remove_data(Customers *customers);
void change_data(Customers *customers);
void print_data(Customers customers);

#endif
