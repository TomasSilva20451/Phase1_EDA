#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "client.h"

struct client *clients_head = NULL;

void load_clients_from_file(char *filename) {
    FILE *fp;
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Erro ao abrir ficheiro.\n");
        return;
    }

    struct client buffer;
    while (fread(&buffer, sizeof(struct client), 1, fp)) {
        insert_client(buffer);
    }

    fclose(fp);
}

void save_clients_to_file(char *filename) {
    FILE *fp;
    fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Erro ao abrir ficheiro.\n");
        return;
    }

    struct client *current = clients_head;
    while (current != NULL) {
        fwrite(current, sizeof(struct client), 1, fp);
        current = current->next;
    }

    fclose(fp);
}

void insert_client(struct client new_client) {
    struct client *new_node = (struct client*) malloc(sizeof(struct client));
    *new_node = new_client;
    new_node->next = NULL;

    if (clients_head == NULL) {
        clients_head = new_node;
    } else {
        struct client *current = clients_head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

struct client *find_client(char *nif) {
    struct client *current = clients_head;
    while (current != NULL) {
        if (strcmp(current->nif, nif) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void remove_client(char *nif) {
    struct client *current = clients_head;
    struct client *previous = NULL;

    while (current != NULL) {
        if (strcmp(current->nif, nif) == 0) {
            if (previous == NULL) {
                clients_head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            printf("Cliente removido com sucesso.\n");
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("Cliente não encontrado.\n");
}

void list_clients() {
    printf("Lista de clientes:\n");
    struct client *current = clients_head;
    while (current != NULL) {
        printf("NIF: %s\n", current->nif);
        printf("Nome: %s\n", current->name);
        printf("Morada: %s\n", current->address);
        printf("Saldo: %.2f\n", current->balance);
        current = current->next;
    }
}

void recharge_balance(char *nif, float value) {
    struct client *current = head;
    while (current != NULL) {
        if (strcmp(current->nif, nif) == 0) {
            current->balance += value;
            printf("Saldo do cliente com NIF %s recarregado com sucesso. Novo saldo: %.2f€\n", current->nif, current->balance);
            return;
        }
        current = current->next;
    }
    printf("Erro: cliente com NIF %s não encontrado.\n", nif);
}

