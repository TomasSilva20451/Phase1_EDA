#include "electric_mobility.h"
#include "client.h"
#include "utils.h"

#ifndef RENTAL_H
#define RENTAL_H

int rent_electric_mobility(char *nif, int id, int duration);
int return_electric_mobility(char *nif, int id);
void list_rent_history();

#endif /* RENTAL_H */
