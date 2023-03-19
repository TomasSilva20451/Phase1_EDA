#ifndef ELECTRIC_MOBILITY_H
#define ELECTRIC_MOBILITY_H

#define MAX_ID_LENGTH 100
#define MAX_NAME_MOBILITY_LENGTH 100
#define MAX_LICENSE_PLATE_LENGTH 10
#define MAX_LOCATION_PLATE_LENGTH 100
#define MAX_PRICE_LENGTH 100
#define MAX_STOCK_LENGTH 100
#define MAX_RENT_LENGTH 100
#define MAX_AUTONOMY_LENGTH 100
#define MAX_BATTERY_LEVEL_LENGTH 100

#include "client.h"

/*
id: an integer representing the unique identifier for the electric mobility object.
name: a pointer to a character array representing the name of the electric mobility object.
license_plate: a pointer to a character array representing the license plate number of the electric mobility object.
location: a pointer to a character array representing the current location of the electric mobility object.
price: a float representing the cost of renting the electric mobility object.
stock: an integer representing the number of electric mobility objects available for rent.
rent: a float representing the cost of renting the electric mobility object per hour.
autonomy: a float representing the distance the electric mobility object can travel on a single charge.
battery_level: an integer representing the current battery level of the electric mobility object.
next: a pointer to the next electric mobility object in a linked list of electric mobility objects.

This typedef declaration renames the electric_mobility struct as ElectricMobility for convenience.*/
typedef struct electric_mobility
{
    int id;
    char *name;
    char *license_plate;
    char *location;
    float price;
    int stock;
    float rent;
    float autonomy;
    int battery_level;
    struct electric_mobility *next;
} ElectricMobility;

extern struct electric_mobility *mobility_head;

/*These are functions related to managing electric mobility in a rental service:

int add_mobility(int id, char *name, char *license_plate, char *location, float price, int stock, float rent, float autonomy, int battery_level): Adds a new electric mobility to the rental service. It takes in various parameters like id, name, license_plate, location, price, stock, rent, autonomy, and battery_level. It returns an integer value indicating whether the addition was successful or not.

void save_electric_mobility_data_to_file(char *filename): Saves the electric mobility data to a file. It takes in the filename as a parameter, opens the file for writing in binary mode, and writes the electric mobility data to the file. It also prints a message indicating whether the operation was successful or not.

void destroy_electric_mobility(ElectricMobility *em): Frees the memory allocated for an electric mobility object. It takes in a pointer to the electric mobility object and frees the memory associated with it.

void read_electric_mobility_file(const char *filename): Reads the electric mobility data from a file. It takes in the filename as a parameter, opens the file for reading in binary mode, reads the electric mobility data from the file, and creates a linked list of electric mobility objects.*/
int add_mobility(int id, char *name, char *license_plate, char *location, float price, int stock, float rent, float autonomy, int battery_level);
void save_electric_mobility_data_to_file(char *filename);
void destroy_electric_mobility(ElectricMobility *em);
void read_electric_mobility_file(const char *filename) ;



#endif /* ELECTRIC_MOBILITY_H */
