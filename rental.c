#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "electric_mobility.h"
#include "rental.h"

ElectricMobility *find_electric_mobility_by_id(int id)
{
    // implementação da função para retornar um ponteiro para a estrutura ElectricMobility
}

int rent_electric_mobility(char *nif, int id, int duration)
{
    ElectricMobility *em = find_electric_mobility_by_id(id);
    if (em == NULL)
    {
        printf("Veículo elétrico com ID %d não encontrado\n", id);
        return 1;
    }

    if (!em->available)
    {
        printf("Veículo elétrico com ID %d não está disponível para aluguel\n", id);
        return 2;
    }

    int rental_cost = duration * em->price_per_hour;

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
    else if (em->battery_level < em->battery_level_per_hour * duration)
    {
        printf("O veículo elétrico não tem carga suficiente para a duração solicitada do aluguel\n");
        return 5;
    }

    Rental rental = {nif, id, duration, rental_cost};
    save_rental_to_file(&rental);

    em->available = 0;
    em->battery_level -= em->battery_level_per_hour * duration;
    save_electric_mobility_to_file(em);

    printf("Veículo elétrico com ID %d alugado para o cliente com NIF %s por %d horas. Custo total: %d euros\n", id, nif, duration, rental_cost);

    return 0;
}