#ifndef CLIENT_H
#define CLIENT_H

#define MAX_NAME_LENGTH 50
#define MAX_ADDRESS_LENGTH 100
#define MAX_ACCOUNTS 5
#define MAX_EMAIL 50
#define MAX_PHONE_NUMBER_LENGTH 15
#define MAX_NIF_LENGTH 20

typedef struct client {
    char name[MAX_NAME_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    int age;
    int phone_number[MAX_PHONE_NUMBER_LENGTH];
    char email[MAX_EMAIL]; 
    int account_numbers[MAX_ACCOUNTS];
    double account_balances[MAX_ACCOUNTS];
    int num_accounts;
    int nif [MAX_NIF_LENGTH];
    struct client* next;
} Client;

Client *new_client(char *name, char *address, int age);

void add_account(Client *client, int account_number, double balance);

void save_clients(char *filename, Client **clients, int num_clients);

void *load_clients(char *filename);

#endif /* CLIENT_H */
