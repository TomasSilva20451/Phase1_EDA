#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "client.h"

static struct client *clients_head = NULL;

void add_client(char *name, char *email, char *phone_number)
{
    struct client *new_node = (struct client *)malloc(sizeof(struct client));
    strncpy(new_node->name, name, MAX_NAME_LENGTH);
    strncpy(new_node->email, email, MAX_EMAIL_LENGTH);
    strncpy(new_node->phone_number, phone_number, MAX_PHONE_NUMBER_LENGTH);
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

void remove_client(char *email)
{
    if (clients_head == NULL)
    {
        return;
    }
    struct client *current = clients_head;
    struct client *previous = NULL;
    while (current != NULL)
    {
        if (strcmp(current->email, email) == 0)
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

void print_all_clients()
{
    struct client *current = clients_head;
    while (current != NULL)
    {
        printf("Nome: %s\n", current->name);
        printf("Email: %s\n", current->email);
        printf("Telefone: %s\n", current->phone_number);
        current = current->next;
    }
}

struct client *get_clients_head()
{
    return clients_head;
}

void load_clients(char *filename)
{
    FILE *fp;
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char phone_number[MAX_PHONE_NUMBER_LENGTH];

    fp = fopen(filename, "rb");
    if (fp == NULL)
    {
        printf("Erro ao abrir arquivo.\n");
        return;
    }

    while (fread(name, MAX_NAME_LENGTH, 1, fp) == 1)
    {
        fread(email, MAX_EMAIL_LENGTH, 1, fp);
        fread(phone_number, MAX_PHONE_NUMBER_LENGTH, 1, fp);
        add_client(name, email, phone_number);
    }

    fclose(fp);
}

void save_clients(char *filename)
{
    FILE *fp;
    fp = fopen(filename, "wb");
    if (fp == NULL)
    {
        printf("Erro ao abrir arquivo.\n");
        return;
    }

    struct client *current = clients_head;
    while (current != NULL)
    {
        fwrite(current->name, MAX_NAME_LENGTH, 1, fp);
        fwrite(current->email, MAX_EMAIL_LENGTH, 1, fp);
        fwrite(current->phone_number, MAX_PHONE_NUMBER_LENGTH, 1, fp);
        current = current->next;
    }

    fclose(fp);
}