// Electric_mobility_means.c
#include "electric_mobility_means.h"
#include <string.h>

typedef struct Electric_mobility_means_s
{
    char name[50];
    int battery_charge;
    float cost;
    char type[50];
    char geocode[50];
} Electric_mobility_means;

void initialize(Electric_mobility_means *mobility_means) {
    strcpy(mobility_means->name, "Name");
    strcpy(mobility_means->geocode, "Geocode"); // add new member 'geocode'
}

void print_data(Electric_mobility_means mobility_means) {
    printf("%s %s\n", mobility_means.name, mobility_means.geocode);
}

// Insert new data (electric mobility means)
void insert_data(Electric_mobility_means *mobility_means)
{
    // insert new mobility means data
    strcpy(mobility_means->name, "Name");
    mobility_means->battery_charge = 50;
    mobility_means->cost = 10.5;
    strcpy(mobility_means->type, "Type");
    strcpy(mobility_means->geocode, "my_geocode"); // add geocode value
}

// Insert new mobility means data
void insert_mobility_means_data(Electric_mobility_means *mobility_means)
{
    strcpy(mobility_means->name, "Name");
    mobility_means->battery_charge = 50;
    mobility_means->cost = 10.5;
    strcpy(mobility_means->type, "Type");
}

// Remove certain mobility means data
void remove_mobility_means_data(Electric_mobility_means *mobility_means)
{
    strcpy(mobility_means->name, "");
    mobility_means->battery_charge = 0;
    mobility_means->cost = 0.0;
    strcpy(mobility_means->type, "");
    strcpy(mobility_means->geocode, ""); // remove geocode value
}

// Change certain mobility means data
void change_mobility_means_data(Electric_mobility_means *mobility_means)
{
    strcpy(mobility_means->name, "New Name");
    mobility_means->battery_charge = 75;
    mobility_means->cost = 15.0;
    strcpy(mobility_means->type, "New Type");
    strcpy(mobility_means->geocode, "my_new_geocode"); // change geocode value
}
