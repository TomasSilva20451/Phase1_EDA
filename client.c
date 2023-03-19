#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "client.h"

struct client *clients_head = NULL;

// add_client
void add_client(char *name, int phone_number, char *email, int nif)
{
    struct client *new_client = malloc(sizeof(struct client));
    if (new_client == NULL)
    {
        printf("Erro ao alocar memória para novo cliente\n");
        return;
    }
    strcpy(new_client->name, name);
    new_client->phone_number = phone_number;
    strcpy(new_client->email, email);
    new_client->nif = nif;
    new_client->next = NULL;
    if (clients_head == NULL)
    {
        clients_head = new_client;
        return;
    }

    struct client *current = clients_head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = new_client;
}

// list_clients 
void list_clients(char *name, int phone_number, char *email, int nif)
{
    struct client *current = clients_head;
    while (current != NULL)
    {
        printf("Name: %s\n", current->name);
        printf("Email: %s\n", current->email);
        printf("Phone number: %d\n", current->phone_number);
        printf("NIF: %d\n", current->nif);
        printf("\n");
        current = current->next;
    }
}

void remove_client(int nif)
{
    struct client *current = clients_head;
    struct client *previous = NULL;

    while (current != NULL)
    {
        if (current->nif == nif)
        {
            if (previous == NULL)
            {
                clients_head = current->next;
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


Client *load_clients(char *filename)
{
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        return 0;
    }

    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL];
    char phone_number[15];
    char nif[20];

    while (fread(name, MAX_NAME_LENGTH - 1, 1, fp) == 1)
    {
        name[MAX_NAME_LENGTH - 1] = '\0';
        fread(email, MAX_EMAIL - 1, 1, fp);
        email[MAX_EMAIL - 1] = '\0';
        fread(phone_number, MAX_PHONE_NUMBER_LENGTH - 1, 1, fp);
        phone_number[MAX_PHONE_NUMBER_LENGTH - 1] = '\0';
        fread(nif, MAX_NIF_LENGTH - 1, 1, fp);
        nif[MAX_NIF_LENGTH - 1] = '\0';

        // add_client(name, email, atoi(phone_number), atoi(nif));
    }

    fclose(fp);
    return clients_head;
}

// update_client_data
void update_client_data(int nif, char *new_email, char *new_phone_number)
{
    struct client *current = clients_head;
    while (current != NULL)
    {
        if (current->nif == nif)
        {
            strcpy(current->email, new_email);
            current->phone_number = atoi(new_phone_number);
            printf("Dados do cliente atualizados com sucesso.\n");
            return;
        }
        current = current->next;
    }
    printf("NIF do cliente não encontrado.\n");
}
