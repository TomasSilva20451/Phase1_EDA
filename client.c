#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "client.h"

struct client *clients_head = NULL;

// add_client
/*function that adds a new client to a singly linked list of clients.
 The function creates a new client node, assigns the client's information
  to the node's fields, and then adds the node to the end of the linked list.
   If the linked list is empty, the new node becomes the head of the linked list.
    The function returns void, and if there is an error allocating memory for the new node,
    an error message is printed.*/
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

// remove_client
/*function that traverses a singly linked list of clients and prints
 out each client's information. The function takes no arguments and
 assumes that the global variable clients_head points to the head of
 the linked list. The function starts at the head of the linked list
 and iterates through each node using a while loop. For each node,
 the function prints out the client's name, email, phone number,
  and NIF using the printf function. After printing the information
   for a client, the function prints a newline character to separate
    the information from the next client's information.
    If the linked list is empty (i.e., clients_head is NULL),
    the function will not print anything.*/
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

// update_client_data
/*function that updates the email and phone number of a
client with a given NIF in a singly linked list.
The function takes three arguments: the client's NIF (an integer)
 and the new email and phone number (strings).
 The function starts at the head of the linked list
  and iterates through each node using a while loop.
   For each node, the function checks if the node's nif field matches
   the given NIF. If a match is found, the function updates
   the node's email field with the new email string using the strcpy
   function and updates the node's phone_number field with the new phone
    number string converted to an integer using the atoi function.
    The function then prints a success message and returns.
    If no match is found for the given NIF, the function prints an error
     message and returns.*/
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

// load_clients file
/*function that reads client data from a binary file and creates a
 singly linked list of clients. The function takes a filename as a
  parameter and returns a pointer to the head of the linked list.
   The function first attempts to open the file in binary mode using 
   the fopen function. If the file cannot be opened, the function prints 
   an error message and returns NULL. The function then reads client data 
   from the file using the fread function, which reads a fixed number of 
   bytes from the file into the specified buffer. 
   The function reads the client's name, email, phone number, 
   and NIF in that order, and uses the add_client 
   function to create a new client node with the read data.
    The function repeats this process until the end of the file is reached. 
    Finally, the function closes the file using the fclose function and returns 
    a pointer to the head of the linked list.*/
Client *load_clients(char *filename)
{
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        return NULL;
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

        add_client(name, atoi(phone_number), email, atoi(nif));
    }

    fclose(fp);
    return clients_head;
}

// save_client_data_to_file
/*This function saves the client data to a binary file specified by the filename parameter. 
It opens the file in write mode and writes each client's data in a sequential manner using fwrite().
 It also formats the phone number and NIF as strings before writing them to the file using snprintf(). 
Finally, it prints a success message and closes the file using fclose().*/
void save_client_data_to_file(char *filename)
{
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    struct client *current = clients_head;
    while (current != NULL)
    {
        fwrite(current->name, MAX_NAME_LENGTH - 1, 1, fp);
        fwrite(current->email, MAX_EMAIL - 1, 1, fp);
        char phone_number[MAX_PHONE_NUMBER_LENGTH];
        snprintf(phone_number, MAX_PHONE_NUMBER_LENGTH, "%d", current->phone_number);
        fwrite(phone_number, MAX_PHONE_NUMBER_LENGTH - 1, 1, fp);
        char nif[MAX_NIF_LENGTH];
        snprintf(nif, MAX_NIF_LENGTH, "%d", current->nif);
        fwrite(nif, MAX_NIF_LENGTH - 1, 1, fp);
        current = current->next;
    }
    printf("Client  data saved to file %s.\n", filename);
    fclose(fp);
}
