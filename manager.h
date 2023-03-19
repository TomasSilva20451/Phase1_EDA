#ifndef MANAGER_H
#define MANAGER_H

#define MAX_MANAGER_NAME_LENGTH 50
#define MAX_MANAGER_EMAIL_LENGTH 100
#define MAX_MANAGER_PASSWORD_LENGTH 20
#define MAX_MANAGER_TYPE_LENGTH 100
#define MAX_MANAGER_DESCRIPTION_LENGTH 100
#define MAX_MANAGER_SALARY_LENGTH 100
#define MAX_MANAGER_PHONE_NUMBER_LENGTH 15

struct manager
{
    char name[MAX_MANAGER_NAME_LENGTH];
    char email[MAX_MANAGER_EMAIL_LENGTH];
    char password[MAX_MANAGER_PASSWORD_LENGTH];
    char type[MAX_MANAGER_TYPE_LENGTH];
    char description[MAX_MANAGER_DESCRIPTION_LENGTH];
    float salary;
    int phone_number;
    struct manager *next;
};

// add_manager
void add_manager(char *name, char *email, char *password, char *type, char *description, float salary, int phone_number);

// list_manager
void list_manager();

// remove_manager
void remove_manager(char *email);

// load_manager_data_from_file
void load_manager_data_from_file(char *filename);

// save_manager_data_to_file
void save_manager_data_to_file(char *filename);


#endif /* MANAGER.H */