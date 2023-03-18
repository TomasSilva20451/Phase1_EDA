#ifndef CLIENT_H
#define CLIENT_H

#define MAX_NAME_LENGTH 50
#define MAX_ADDRESS_LENGTH 100
#define MAX_ACCOUNTS 5
#define MAX_EMAIL 50
#define MAX_PHONE_NUMBER_LENGTH 15
#define MAX_NIF_LENGTH 20
typedef struct client
{
    char name[100];
    int phone_number;
    char email[100];
    int nif;
    struct client *next;
} Client;

extern struct client *clients_head;

void add_client(char *name, int phone_number, char *email, int nif);
/*
typedef struct client {
    char name[MAX_NAME_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    int age;
    int phone_number;
    char email[MAX_EMAIL];
    int account_numbers[MAX_ACCOUNTS];
    double account_balances[MAX_ACCOUNTS];
    int num_accounts;
    int nif;
    struct client* next;
} Client;
*/
// add_client
// void add_client(char *name, int phone_number, char *email, int nif);

Client *new_client(char *name, char *address, int phone_number, int nif);

void add_account(Client *client, int account_number, double balance);

void save_clients(char *filename, Client **clients, int num_clients);

Client *load_clients(char *filename);

#endif /* CLIENT_H */
