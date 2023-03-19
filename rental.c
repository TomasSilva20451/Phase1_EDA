// rental.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "electric_mobility.h"
#include "rental.h"

typedef struct
{
    char *nif;
    int id;
    int duration;
    int rental_cost;
    time_t timestamp;
} Rental;

//Fazer na fase 2, melhorar o aluguer

//void save_rental_to_file(Rental *rental);
//void save_electric_mobility_to_file(ElectricMobility *em);




