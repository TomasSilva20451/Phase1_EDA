#ifndef RENTAL_H
#define RENTAL_H

#include "electric_mobility.h"
#include "client.h"
#include "utils.h"

#define RENTAL_HISTORY_FILE "rental_history.bin"

struct rental {
    char rental_id[11];
    char nif[10];
    char license_plate[9];
    char rental_date[11];
    char return_date[11];
};

void rent_electric_mobility(char *nif, char *license_plate);
void return_electric_mobility(char *rental_id);
void list_rent_history();

#endif
