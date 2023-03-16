#ifndef ELECTRIC_MOBILITY_H
#define ELECTRIC_MOBILITY_H

#include "client.h"

typedef struct electric_mobility ElectricMobility;

ElectricMobility* create_electric_mobility(int id, float price_per_kwh);
void destroy_electric_mobility(ElectricMobility* em);
float get_price_per_kwh(ElectricMobility* em);
void set_price_per_kwh(ElectricMobility* em, float price_per_kwh);
float calculate_price(ElectricMobility* em, Client* client, float kwh);

#endif /* ELECTRIC_MOBILITY_H */
