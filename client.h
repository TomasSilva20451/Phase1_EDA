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

/*This is an external declaration of a variable named clients_head of type struct client *.
 This variable is declared as extern to indicate that it is defined in another source file, 
 and it allows other source files to access and use it.*/
extern struct client *clients_head;

// add_client
/*A function prototype is a declaration of a function that provides the function's name,
 return type, and parameter types to the compiler, but does not contain the function's actual implementation. 
 It is used to inform the compiler about the existence of a function so that it can be called from other parts of the program.*/
void add_client(char *name, int phone_number, char *email, int nif);

// save_client_data_to_file
/*The function save_client_data_to_file is used to save the data of all the clients to a file 
with the specified name. 
The function takes a pointer to a character string filename as input and returns nothing.
 The function opens the file in binary write mode and writes the data of each client to the 
 file one by one using fwrite() function. 
 After writing all the data to the file, it closes the file and prints a message indicating 
 that the client data has been saved to the file.*/
void save_client_data_to_file(char *filename) ;


Client *new_client(char *name, char *address, int phone_number, int nif);

/*This function adds a new account to a given client. 
It takes a pointer to the client to which the account should be added, 
as well as the account number and initial balance.*/
void add_account(Client *client, int account_number, double balance);

/* This function saves an array of clients to a file. 
It takes the filename to which the clients should be saved, 
a pointer to an array of client pointers, and the number of clients in the array.*/
void save_clients(char *filename, Client **clients, int num_clients);

Client *load_clients(char *filename);

#endif /* CLIENT_H */
