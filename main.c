// main.c
#include <stdio.h>
#include "customers.h"

// Define a dynamic data structure for the representation of electric mobility means, customers and managers
typedef struct
{
    char name[50];
    int battery_charge;
    float cost;
    char type[50];
    char geocode[50]; // add geocode member
} Electric_mobility_means;

typedef struct
{
    char name[50];
    char NIF[50];
    float balance;
    char address[50];
} Customers;

typedef struct
{
    char name[50];
    char NIF[50];
    char address[50];
} Managers;

// Read and write data in text and binary files
void read_data()
{
    FILE *fp;
    fp = fopen("input.txt", "r");
    // read data from input.txt
    fclose(fp);
}

void write_data()
{
    FILE *fp;
    fp = fopen("output.txt", "w");
    // write data to output.txt
    fclose(fp);
}

// Insert new data (customer/manager/electric mobility means)
void insert_data(Electric_mobility_means *mobility_means, Customers *customers, Managers *managers)
{
    // insert new mobility means data
    strcpy(mobility_means->name, "Name");
    mobility_means->battery_charge = 50;
    mobility_means->cost = 10.5;
    strcpy(mobility_means->type, "Type");

    // insert new customers data
    strcpy(customers->name, "Name");
    strcpy(customers->NIF, "NIF");
    customers->balance = 10.0;
    strcpy(customers->address, "Address");

    // insert new managers data
    strcpy(managers->name, "Name");
    strcpy(managers->NIF, "NIF");
    strcpy(managers->address, "Address");
    strcpy(mobility_means->geocode, "Geocode"); // add new member 'geocode'
}

// Remove certain data (customer/manager/electric mobility means)
void remove_data(Electric_mobility_means *mobility_means, Customers *customers, Managers *managers)
{
    // remove mobility means data
    strcpy(mobility_means->name, "");
    mobility_means->battery_charge = 0;
    mobility_means->cost = 0.0;
    strcpy(mobility_means->type, "");

    // remove customers data
    strcpy(customers->name, "");
    strcpy(customers->NIF, "");
    customers->balance = 0.0;
    strcpy(customers->address, "");

    // remove managers data
    strcpy(managers->name, "");
    strcpy(managers->NIF, "");
    strcpy(managers->address, "");
}

// Change certain data (customer/manager/electric mobility means)
void change_data(Electric_mobility_means *mobility_means, Customers *customers, Managers *managers)
{
    // change mobility means data
    strcpy(mobility_means->name, "New Name");
    mobility_means->battery_charge = 75;
    mobility_means->cost = 15.0;
    strcpy(mobility_means->type, "New Type");

    // change customers data
    strcpy(customers->name, "New Name");
    strcpy(customers->NIF, "New NIF");
    customers->balance = 15.0;
    strcpy(customers->address, "New Address");

    // change managers data
    strcpy(managers->name, "New Name");
    strcpy(managers->NIF, "New NIF");
    strcpy(managers->address, "New Address");
}

// Register rental of a certain electric mobility means
void register_rental(Electric_mobility_means *mobility_means)
{
    // register rental of mobility means
    printf("Rental of %s with battery charge of %d and cost of %f registered!\n", mobility_means->name, mobility_means->battery_charge, mobility_means->cost);
}

// List electric mobility means in descending order of autonomy
void list_by_autonomy(Electric_mobility_means *mobility_means, int size)
{
    int i, j;
    Electric_mobility_means temp;

    // sort mobility means by battery charge in descending order
    for (i = 0; i < size; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            if (mobility_means[i].battery_charge < mobility_means[j].battery_charge)
            {
                temp = mobility_means[i];
                mobility_means[i] = mobility_means[j];
                mobility_means[j] = temp;
            }
        }
    }

    // list mobility means in descending order of battery charge
    for (i = 0; i < size; i++)
    {
        printf("Name: %s, Battery Charge: %d, Cost: %f, Type: %s\n", mobility_means[i].name, mobility_means[i].battery_charge, mobility_means[i].cost, mobility_means[i].type);
    }
}

// List electric mobility means existing in a location with a certain geocode
void list_by_geocode(Electric_mobility_means *mobility_means, int size, char *geocode)
{
    int i;

    // list mobility means in a location with a certain geocode
    for (i = 0; i < size; i++)
    {
        if (strcmp(mobility_means[i].geocode, geocode) == 0)
        {
            printf("Name: %s, Battery Charge: %d, Cost: %f, Type: %s\n", mobility_means[i].name, mobility_means[i].battery_charge, mobility_means[i].cost, mobility_means[i].type);
        }
    }
}

int main()
{
    Customers customers[100];
    Electric_mobility_means mobility_means[100];
    Managers managers[100];
    int size = 5;
    char geocode[50] = "my_geocode";

    // read data from text file
    read_data();

    // register rental of a certain electric mobility means
    register_rental(&mobility_means[0]);

    // list electric mobility means in descending order of autonomy
    list_by_autonomy(mobility_means, size);

    // list electric mobility means existing in a location with a certain geocode
    list_by_geocode(mobility_means, size, geocode);

    // write data to text file
    write_data();

    // insert data
    insert_data(customers);

    // remove data
    remove_data(customers);

    // change data
    change_data(customers);

    return 0;
}