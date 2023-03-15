#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "electric_mobility.h"

struct electric_mobility *electric_mobility_head = NULL;

/* Função para carregar os dados dos meios de mobilidade elétrica a partir de um ficheiro binário */
void load_electric_mobility_data() {
    FILE *fptr;
    struct electric_mobility data;

    fptr = fopen("electric_mobility.bin", "rb");
    if (fptr == NULL) {
        printf("Erro ao abrir o ficheiro electric_mobility.bin\n");
        return;
    }

    while (fread(&data, sizeof(struct electric_mobility), 1, fptr) == 1) {
        struct electric_mobility *new_electric_mobility = (struct electric_mobility*) malloc(sizeof(struct electric_mobility));
        strcpy(new_electric_mobility->code, data.code);
        strcpy(new_electric_mobility->type, data.type);
        strcpy(new_electric_mobility->location_geocode, data.location_geocode);
        new_electric_mobility->battery_level = data.battery_level;
        new_electric_mobility->rental_cost = data.rental_cost;
        new_electric_mobility->next = electric_mobility_head;
        electric_mobility_head = new_electric_mobility;
    }

    fclose(fptr);
}

/* Função para guardar os dados dos meios de mobilidade elétrica num ficheiro binário */
void save_electric_mobility_data() {
    FILE *fptr;
    struct electric_mobility *current = electric_mobility_head;

    fptr = fopen("electric_mobility.bin", "wb");
    if (fptr == NULL) {
        printf("Erro ao abrir o ficheiro electric_mobility.bin\n");
        return;
    }

    while (current != NULL) {
        fwrite(current, sizeof(struct electric_mobility), 1, fptr);
        current = current->next;
    }

    fclose(fptr);
}

/* Função para inserir um novo meio de mobilidade elétrica na lista */
void insert_electric_mobility(struct electric_mobility new_electric_mobility) {
    struct electric_mobility *new_node = (struct electric_mobility*) malloc(sizeof(struct electric_mobility));
    strcpy(new_node->code, new_electric_mobility.code);
    strcpy(new_node->type, new_electric_mobility.type);
    strcpy(new_node->location_geocode, new_electric_mobility.location_geocode);
    new_node->battery_level = new_electric_mobility.battery_level;
    new_node->rental_cost = new_electric_mobility.rental_cost;
    new_node->next = electric_mobility_head;
    electric_mobility_head = new_node;
/* Função para inserir um novo meio de mobilidade elétrica na lista */
void insert_electric_mobility(struct electric_mobility new_mobility) {
    /* Aloca memória para o novo nó */
    struct electric_mobility_node *new_node = (struct electric_mobility_node*) malloc(sizeof(struct electric_mobility_node));

    /* Define os valores do novo nó */
    new_node->mobility = new_mobility;
    new_node->next = NULL;

    /* Adiciona o novo nó à lista */
    if (electric_mobility_head == NULL) {
        /* Lista vazia */
        electric_mobility_head = new_node;
        electric_mobility_tail = new_node;
    } else {
        /* Lista não vazia */
        electric_mobility_tail->next = new_node;
        electric_mobility_tail = new_node;
    }
}

