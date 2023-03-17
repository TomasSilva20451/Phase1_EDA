#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "client.h"

struct client *clients_head = NULL;

void add_client(char *name, char *email, int phone_number, int nif)
{
    int aux = phone_number;

    struct client *new_node = malloc(sizeof(struct client *));
    strncpy(new_node->name, name, MAX_NAME_LENGTH - 1);
    // new_node->name[MAX_NAME_LENGTH - 1] = '\0';
    strncpy(new_node->email, email, MAX_EMAIL - 1);
    // new_node->email[MAX_EMAIL - 1] = '\0';
    new_node->phone_number = aux;
    // new_node->phone_number[MAX_PHONE_NUMBER_LENGTH - 1] = '\0';
    new_node->nif = nif;
    // new_node->nif[MAX_NIF_LENGTH - 1] = '\0';
    new_node->next = NULL;

    if (clients_head == NULL)
    {
        clients_head = new_node;
    }
    else
    {
        struct client *current = clients_head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = new_node;
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

void list_clients()
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

        add_client(name, email, atoi(phone_number), atoi(nif));
    }

    fclose(fp);
    return clients_head;
}
/*void save_clients(char *filename)
{
    FILE *outfile = fopen(filename, "w");
    if (outfile == NULL)
    {
        fprintf(stderr, "Error opening file %s for writing\n", filename);
        return;
    }

    for (int i = 0; i < num_clients; i++)
    {
        fprintf(outfile, "%s,%s,%s,%d\n", clients[i].name, clients[i].email,
                clients[i].phone, clients[i].age);
    }

    fclose(outfile);
    printf("Saved %d clients to %s\n", num_clients, filename);
}*/
