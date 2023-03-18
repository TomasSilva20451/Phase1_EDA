#ifndef MANAGER_H
#define MANAGER_H

#define MAX_MANAGER_NAME_LENGTH 50
#define MAX_MANAGER_EMAIL_LENGTH 50
#define MAX_MANAGER_PASSWORD_LENGTH 50
#define MAX_MANAGER_TYPE_LENGTH 50
#define MAX_MANAGER_LOCATION_GEOCODE_LENGTH 50
#define MAX_MANAGER_DESCRIPTION_LENGTH 100

struct manager
{
    char name[MAX_MANAGER_NAME_LENGTH];
    char email[MAX_MANAGER_EMAIL_LENGTH];
    char password[MAX_MANAGER_PASSWORD_LENGTH];
    char type[MAX_MANAGER_TYPE_LENGTH];
    char location_geocode[MAX_MANAGER_LOCATION_GEOCODE_LENGTH];
    float autonomy;
    float battery_level;
    float cost;
    char description[MAX_MANAGER_DESCRIPTION_LENGTH];
    float salary;
    int phone_number;
    struct manager *next;
};

void print_all_managers();
void add_manager(char *email, char *name, char *password, int phone_number);

void delete_manager(char *email);
void update_manager_info(char *email, char *new_name, char *new_password, char *new_type, char *new_location_geocode, float new_autonomy, float new_battery_level, float new_cost, char *new_description);
void save_manager_data_to_file(char *filename);
void load_manager_data_from_file(char *filename);

#endif
