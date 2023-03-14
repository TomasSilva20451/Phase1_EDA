// customers.h 
#ifndef CUSTOMERS_H
#define CUSTOMERS_H

#include "electric_mobility_means.h"

typedef struct
{
    char name[50];
    char NIF[50];
    float balance;
    char address[50];
} CustomerData;

void insert_data(Customers *customers);
void remove_data(Customers *customers);
void change_data(Customers *customers);

#endif // CUSTOMERS_H