#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "electric_mobility.h"
#include "client.h"
#include "rental.h"
#include "utils.h"

#define MAX_RENTALS 1000

struct rental rentals[MAX_RENTALS];
int num_rentals = 0;

/* Função para realizar o aluguel de um meio de mobilidade elétrica */
int rent_electric_mobility(char *nif, int id, int duration) {
    struct client *client = find_client_by_nif(nif);
    if (client == NULL) {
        printf("Cliente não encontrado.\n");
        return 0;
    }
    struct electric_mobility *mobility = find_electric_mobility_by_id(id);
    if (mobility == NULL) {
        printf("Meio de mobilidade elétrica não encontrado.\n");
        return 0;
    }
    if (mobility->status == UNAVAILABLE) {
        printf("Meio de mobilidade elétrica já alugado.\n");
        return 0;
    }
    float price = duration * mobility->price_per_minute;
    if (client->balance < price) {
        printf("Saldo insuficiente para realizar o aluguel.\n");
        return 0;
    }
    client->balance -= price;
    mobility->status = UNAVAILABLE;
    struct rental new_rental = {
        .client_nif = nif,
        .electric_mobility_id = id,
        .duration = duration,
        .price = price
    };
    rentals[num_rentals] = new_rental;
    num_rentals++;
    printf("Aluguel realizado com sucesso.\n");
    return 1;
}

/* Função para realizar a devolução de um meio de mobilidade elétrica */
int return_electric_mobility(char *nif, int id) {
    struct rental *rental = find_rental_by_client_and_mobility(nif, id);
    if (rental == NULL) {
        printf("Aluguel não encontrado.\n");
        return 0;
    }
    struct electric_mobility *mobility = find_electric_mobility_by_id(id);
    if (mobility == NULL) {
        printf("Meio de mobilidade elétrica não encontrado.\n");
        return 0;
    }
    if (mobility->status == AVAILABLE) {
        printf("Meio de mobilidade elétrica já está disponível.\n");
        return 0;
    }
    mobility->status = AVAILABLE;
    printf("Meio de mobilidade elétrica devolvido com sucesso.\n");
    return 1;
}

/* Função para listar o histórico de alugueis */
void list_rent_history() {
    printf("Histórico de Aluguéis:\n");
    for (int i = 0; i < num_rentals; i++) {
        printf("Cliente: %s | Meio de Mobilidade Elétrica: %d | Duração: %d | Preço: %.2f€\n",
            rentals[i].client_nif, rentals[i].electric_mobility_id, rentals[i].duration, rentals[i].price);
    }
}
