// manager.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "manager.h"

#define MANAGER_DATA_FILE_HEADER "MANAGER_DATA_FILE\n"

struct manager *managers_head = NULL;

// add_manager
void add_manager(char *name, char *email, char *password, char *type, char *description, float salary, int phone_number)
{
    struct manager *new_manager = malloc(sizeof(struct manager));
    if (new_manager == NULL)
    {
        printf("Erro ao alocar memória para novo gestor\n");
        return;
    }
    strcpy(new_manager->name, name);
    strcpy(new_manager->email, email);
    strcpy(new_manager->password, password);
    strcpy(new_manager->type, type);
    strcpy(new_manager->description, description);
    new_manager->salary = salary;

    new_manager->phone_number = phone_number;
    new_manager->next = NULL;

    if (managers_head == NULL)
    {
        managers_head = new_manager;
        return;
    }

    struct manager *current = managers_head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = new_manager;
}

void remove_manager(char *email)
{
    struct manager *current = managers_head;
    struct manager *previous = NULL;

    while (current != NULL)
    {
        if (strcmp(current->email, email))
        {
            if (previous == NULL)
            {
                managers_head = current->next;
            }
            else
            {
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}
void list_manager(){
    struct manager *current = managers_head;
    while (current != NULL)
    {
        printf("Name: %s\n", current->name);
        printf("Email: %s\n", current->email);
        printf("Phone number: %d\n", current->phone_number);
        printf("type: %s\n", current->type);
        printf("description: %s\n", current->description);
        printf("salary: %f\n", current->salary);
        printf("\n");
        current = current->next;
    }
}

// load_manager_data_from_file
void load_manager_data_from_file(char *filename)
{
    FILE *file = fopen(filename, "rb");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo %s\n", filename);
        return;
    }

    char header[sizeof(MANAGER_DATA_FILE_HEADER)];
    fread(header, sizeof(char), sizeof(MANAGER_DATA_FILE_HEADER), file);

    if (strcmp(header, MANAGER_DATA_FILE_HEADER) != 0)
    {
        printf("Arquivo %s inválido\n", filename);
        return;
    }

    struct manager manager_data;
    while (fread(&manager_data, sizeof(struct manager), 1, file) == 1)
    {
        add_manager(manager_data.name, manager_data.email, manager_data.password, manager_data.type, manager_data.description, manager_data.salary, manager_data.phone_number);
    }

    fclose(file);
}

// save_manager_data_to_file
void save_manager_data_to_file(char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Erro ao criar o arquivo %s\n", filename);
        return;
    }

    size_t header_size = sizeof(MANAGER_DATA_FILE_HEADER);
    if (fwrite(MANAGER_DATA_FILE_HEADER, sizeof(char), header_size, file) != header_size) {
        printf("Erro ao escrever o cabeçalho no arquivo %s\n", filename);
        fclose(file);
        return;
    }

    struct manager *current = managers_head;
    while (current != NULL) {
        if (fwrite(current, sizeof(struct manager), 1, file) != 1) {
            printf("Erro ao escrever os dados do gestor no arquivo %s\n", filename);
            fclose(file);
            return;
        }
        current = current->next;
    }

    fclose(file);
}

