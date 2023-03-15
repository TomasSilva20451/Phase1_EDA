#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "manager.h"

/* Variável global que representa a cabeça da lista de gestores */
struct manager *managers_head = NULL;

/* Função para carregar os dados dos gestores a partir de um ficheiro binário */
void load_managers_data(char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file != NULL) {
        struct manager new_manager;
        while (fread(&new_manager, sizeof(struct manager), 1, file)) {
            insert_manager(new_manager);
        }
        fclose(file);
    }
}

/* Função para guardar os dados dos gestores num ficheiro binário */
void save_managers_data(char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file != NULL) {
        struct manager *current = managers_head;
        while (current != NULL) {
            fwrite(current, sizeof(struct manager), 1, file);
            current = current->next;
        }
        fclose(file);
    }
}

/* Função para inserir um novo gestor na lista */
void insert_manager(struct manager new_manager) {
    if (managers_head == NULL) {
        /* Lista vazia */
        struct manager *new_node = (struct manager*) malloc(sizeof(struct manager));
        *new_node = new_manager;
        new_node->next = NULL;
        managers_head = new_node;
    } else {
        /* Procura a última posição da lista */
        struct manager *current = managers_head;
        while (current->next != NULL) {
            current = current->next;
        }
        /* Cria um novo nó na última posição */
        struct manager *new_node = (struct manager*) malloc(sizeof(struct manager));
        *new_node = new_manager;
        new_node->next = NULL;
        current->next = new_node;
    }
}

/* Função para remover um gestor da lista */
void remove_manager(char *email) {
    struct manager *current = managers_head;
    struct manager *previous = NULL;
    while (current != NULL) {
        if (strcmp(current->email, email) == 0) {
            /* O gestor foi encontrado, remove-o da lista */
            if (previous == NULL) {
                /* O gestor é o primeiro da lista */
                managers_head = current->next;
            } else {
                /* O gestor está no meio ou no fim da lista */
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

/* Função para atualizar a informação de um gestor */
void update_manager_info(char *email, char *new_name, char *new_password) {
    struct manager *current = managers_head;
    while (current != NULL) {
        if (strcmp(current->email, email) == 0) {
            /* O gestor foi encontrado, atualiza a informação */
            if (new_name != NULL) {
                strcpy(current->name, new_name);
            }
            if (new_password != NULL) {
                strcpy(current->password, new_password);
            }
            return;
        }
        current = current->next;
    }
}

/* Função para listar todos os gestores */
void list_all_managers() {
    printf("Lista de Gestores:\n");
    struct manager *current = managers_head;
    while (current != NULL) {
        printf("Nome: %s\n", current->name);
        printf("Email:%s\n", current->email);
printf("Contacto: %s\n", current->phone);
printf("NIF: %s\n", current->nif);
printf("\n");
current = current->next;
}
}
