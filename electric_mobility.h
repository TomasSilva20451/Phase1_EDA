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


int add_mobility(int id, char *name, char *license_plate, char *location, float price, int stock, float rent, float autonomy, int battery_level);
void save_electric_mobility_data_to_file(char *filename);
void destroy_electric_mobility(ElectricMobility *em);
void read_electric_mobility_file(const char *filename) ;



#endif /* ELECTRIC_MOBILITY_H */
