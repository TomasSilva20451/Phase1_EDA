#ifndef RENTAL_H
#define RENTAL_H

#include "electric_mobility.h"
#include "client.h"
#include "utils.h"

#define MAX_RENTALS 1000
#define RENTAL_HISTORY_FILE "rental_history.bin"

struct rental
{
    char client_nif[10];
    int electric_mobility_id;
    int duration;
    float price;
};

int rent_electric_mobility(char *nif, int id, int duration);
int return_electric_mobility(char *nif, int id);
void list_rent_history();

#endif /* RENTAL_H */