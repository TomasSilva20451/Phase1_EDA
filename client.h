#ifndef CLIENT_H
#define CLIENT_H

#define MAX_CLIENTS 100

struct client
{
    char name[101];
    char email[101];
    char phone_number[21];
    char nif[10];
};

void add_client(char *name, char *email, char *phone_number, char *nif);
void list_clients();
void search_client();
void delete_client();
void save_client_data_to_file(char *filename);
void load_client_data_from_file(char *filename);
int get_num_clients();
struct client *get_client_by_index(int index);
int get_client_index_by_nif(char *nif);

#endif