#ifndef CLIENT_H
#define CLIENT_H

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100
#define MAX_PHONE_NUMBER_LENGTH 15

struct client {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char phone_number[MAX_PHONE_NUMBER_LENGTH];
    struct client *next;
};

void print_all_clients();
void add_client(char *name, char *email, char *phone_number);
void remove_client(char *email);

#endif /* CLIENT_H */