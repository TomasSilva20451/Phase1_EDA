#ifndef CLIENT_H
#define CLIENT_H

struct client {
    char nif[10];
    char name[100];
    char address[100];
    float balance;
    struct rental *rentals_head;
};

void load_clients_from_file(char *filename);
void save_clients_to_file(char *filename);
void insert_client(struct client new_client);
struct client *find_client(char *nif);
void remove_client(char *nif);
void list_clients();
void recharge_balance(char *nif, float value);
void add_rental_to_client(char *nif, struct rental *new_rental);

#endif /* CLIENT_H */
