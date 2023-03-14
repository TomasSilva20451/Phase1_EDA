// customers.c 
#include "customers.h"

// Insert new data (customers)
void insert_data(Customers *customers)
{
    // insert new customers data
    strcpy(customers->name, "Name");
    strcpy(customers->NIF, "NIF");
    customers->balance = 10.0;
    strcpy(customers->address, "Address");
}

// Remove certain data (customers)
void remove_data(Customers *customers)
{
    // remove customers data
    strcpy(customers->name, "");
    strcpy(customers->NIF, "");
    customers->balance = 0.0;
    strcpy(customers->address, "");
}

// Change certain data (customers)
void change_data(Customers *customers)
{
    // change customers data
    strcpy(customers->name, "New Name");
    strcpy(customers->NIF, "New NIF");
    customers->balance = 15.0;
    strcpy(customers->address, "New Address");
}