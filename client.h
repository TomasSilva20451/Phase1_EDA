#ifndef CLIENT_H
#define CLIENT_H

#define MAX_NAME_LENGTH 50
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

// add_client
void add_client(char *name, int phone_number, char *email, int nif);

// save_client_data_to_file
void save_client_data_to_file(char *filename) ;


Client *new_client(char *name, char *address, int phone_number, int nif);

void add_account(Client *client, int account_number, double balance);

void save_clients(char *filename, Client **clients, int num_clients);

Client *load_clients(char *filename);

#endif /* CLIENT_H */
