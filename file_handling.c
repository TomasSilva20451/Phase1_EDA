#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "electric_mobility.h"
#include "client.h"
#include "manager.h"
#include "file_handling.h"

/* Função para ler os dados dos gestores a partir de um ficheiro binário */
void read_managers_file(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Erro ao abrir o ficheiro.\n");
        return;
    }

    struct manager m;
    while (fread(&m, sizeof(struct manager), 1, fp)) {
        insert_manager(m);
    }

    fclose(fp);
}

/* Função para escrever os dados dos gestores para um ficheiro binário */
void write_managers_file(char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Erro ao abrir o ficheiro.\n");
        return;
    }

    struct manager *current = managers_head;
    while (current != NULL) {
        fwrite(current, sizeof(struct manager), 1, fp);
        current = current->next;
    }

    fclose(fp);
}

/* Função para ler os dados dos clientes a partir de um ficheiro binário */
void read_clients_file(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Erro ao abrir o ficheiro.\n");
        return;
    }

    struct client c;
    while (fread(&c, sizeof(struct client), 1, fp)) {
        insert_client(c);
    }

    fclose(fp);
}

/* Função para escrever os dados dos clientes para um ficheiro binário */
void write_clients_file(char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Erro ao abrir o ficheiro.\n");
        return;
    }

    struct client *current = clients_head;
    while (current != NULL) {
        fwrite(current, sizeof(struct client), 1, fp);
        current = current->next;
    }

    fclose(fp);
}

/* Função para ler os dados dos meios de mobilidade elétrica a partir de um ficheiro binário */
void read_electric_mobility_file(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Erro ao abrir o ficheiro.\n");
        return;
    }

    struct electric_mobility em;
    while (fread(&em, sizeof(struct electric_mobility), 1, fp)) {
        insert_electric_mobility(em);
    }

    fclose(fp);
}

/* Função para escrever os dados dos meios de mobilidade elétrica para um ficheiro binário */
void write_electric_mobility_file(char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Erro ao abrir o ficheiro.\n");
        return;
    }

    struct electric_mobility *current = electric_mobility_head;
    while (current != NULL) {
        fwrite(current, sizeof(struct electric_mobility), 1, fp);
        current = current->next;
    }

    fclose(fp);
}

