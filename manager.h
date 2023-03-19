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
    char *name;
    char *email;
    char *password;
    char *type;
    char *description;
    float salary;
    int phone_number;
    struct manager *next;
};

// add_manager
void add_manager(char *name, char *email, char *password, char *type, char *description, float salary, int phone_number);






// void delete_manager(char *email);
/*
void print_all_managers();
void update_manager_info(char *email, char *new_name, char *new_password, char *new_type, char *new_location_geocode, float new_autonomy, float new_battery_level, float new_cost, char *new_description);
void save_manager_data_to_file(char *filename);
void load_manager_data_from_file(char *filename);
*/
#endif /* MANAGER.H */