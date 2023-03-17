#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "electric_mobility.h"
#include "rental.h"

void rent_electric_mobility(int nif, int id)
{
    Electric_mobility *em = find_electric_mobility_by_id(id);

    if (em == NULL)
    {
        printf("Electric mobility with ID %d not found\n", id);
        return;
    }

    if (!em->available)
    {
        printf("Electric mobility with ID %d is not available for rental\n", id);
        return;
    }

    Rental rental = {nif, id};
    save_rental_to_file(&rental);

    em->available = 0;
    save_electric_mobility_to_file(em);

    printf("Electric mobility with ID %d rented to customer with NIF %d\n", id, nif);
}
void return_electric_mobility(int nif, int id)
{
    Rental *current_rental = find_rental_by_nif_and_id(nif, id);
    if (current_rental == NULL)
    {
        printf("No rental found with NIF %d and Electric Mobility ID %d\n", nif, id);
        return;
    }
    ElectricMobility *em = current_rental->em;
    if (em == NULL)
    {
        printf("Electric Mobility with ID %d is not currently rented\n", id);
        return;
    }
    int rental_hours = (int)ceil(difftime(time(NULL), current_rental->start_time) / 3600.0);
    double total_cost = rental_hours * em->price_per_hour;
    printf("Total cost for rental with NIF %d and Electric Mobility ID %d is: %.2f euros\n", nif, id, total_cost);
    em->available = true;
    current_rental->em = NULL;
}