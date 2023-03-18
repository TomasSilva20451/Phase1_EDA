#ifndef ELECTRIC_MOBILITY_H
#define ELECTRIC_MOBILITY_H

#include "client.h"

typedef struct electric_mobility
{
    int id;
    char *name;
    float price;
    int stock;
    float rent;
    float autonomy;
    int battery_level;
    int max_rental_duration;
    int battery_level_per_minute;
    struct electric_mobility *next;
} ElectricMobility;

// create_electric_mobility_list
/*void print_electric_mobility(ElectricMobility *em);
ElectricMobilityList *list = (ElectricMobilityList *)malloc(sizeof(ElectricMobilityList));
list->head = NULL;
list->size = 0;
*/

void destroy_electric_mobility(ElectricMobility *em);
float get_price_per_kwh(ElectricMobility *em);
void set_price_per_kwh(ElectricMobility *em, float price_per_kwh);
float calculate_price(ElectricMobility *em, Client *client, float kwh);

#endif /* ELECTRIC_MOBILITY_H */
