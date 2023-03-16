#ifndef CLIENT_H
#define CLIENT_H

#define MAX_NAME_LENGTH 50
#define MAX_ADDRESS_LENGTH 100
#define MAX_ACCOUNTS 5

typedef struct {
    char name[MAX_NAME_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    int age;
    int account_numbers[MAX_ACCOUNTS];
    double account_balances[MAX_ACCOUNTS];
    int num_accounts;
} Client;

Client *new_client(char *name, char *address, int age);

void add_account(Client *client, int account_number, double balance);

void save_clients(char *filename, Client **clients, int num_clients);

Client **load_clients(char *filename, int *num_clients);

#endif /* CLIENT_H */
