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

void save_rental_to_file(Rental *rental);
void save_electric_mobility_to_file(ElectricMobility *em);

ElectricMobility *find_electric_mobility_by_id(ElectricMobility *electric_mobility_list,int id)
{
    ElectricMobility *em = electric_mobility_list;
    while (em != NULL)
    {
        if (em->id == id)
        {
            return em;
        }
        em = em->next;
    }
    return NULL;
}

int rent_electric_mobility(ElectricMobility *electric_mobility_list ,char *nif, int id, int duration)
{
    ElectricMobility *em = find_electric_mobility_by_id(electric_mobility_list, id);
    if (em == NULL)
    {
        printf("Veículo elétrico com ID %d não encontrado\n", id);
        return 1;
    }
    else
    {
        printf("Veículo elétrico com ID %d não está disponível para aluguel\n", id);
        return 2;
    }

    int rental_cost = duration * em->price;

    if (duration <= 0)
    {
        printf("Duração inválida do aluguel\n");
        return 3;
    }
    else if (duration > em->max_rental_duration)
    {
        printf("A duração máxima permitida do aluguel é de %d horas\n", em->max_rental_duration);
        return 4;
    }
    else if (em->battery_level < em->battery_level_per_minute * duration)
    {
        printf("O veículo elétrico não tem carga suficiente para a duração solicitada do aluguel\n");
        return 5;
    }

    Rental rental;
    rental.nif = strdup(nif);
    rental.id = id;
    rental.duration = duration;
    rental.rental_cost = rental_cost;
    rental.timestamp = time(NULL);

    save_rental_to_file(&rental);

    //em->available = 0; -- Caso seja necessario guardar o estado
    em->battery_level -= em->battery_level_per_minute * duration;
    save_electric_mobility_to_file(em);

    printf("Veículo elétrico com ID %d alugado para o cliente com NIF %s por %d horas. Custo total: %d euros\n", id, nif, duration, rental_cost);

    return 0;
}
