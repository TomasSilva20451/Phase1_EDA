#ifndef ELECTRIC_MOBILITY_H
#define ELECTRIC_MOBILITY_H

#include "client.h"

typedef struct electric_mobility
{
    int id;
    char name[30];
    float price;
    int stock;
    float rent;
    float autonomy;
    int battery_level;
    int max_rental_duration; // novo membro adicionado
    struct electric_mobility *next;
} ElectricMobility;

ElectricMobility *create_electric_mobility(int id, char *name, float price, int stock, float rent, float autonomy, int battery_level);
void destroy_electric_mobility(ElectricMobility *em);
float get_price_per_kwh(ElectricMobility *em);
void set_price_per_kwh(ElectricMobility *em, float price_per_kwh);
float calculate_price(ElectricMobility *em, Client *client, float kwh);

#endif /* ELECTRIC_MOBILITY_H */
