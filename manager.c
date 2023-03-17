// manager.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "manager.h"

#define MANAGER_DATA_FILE_HEADER "MANAGER_DATA_FILE\n"

struct manager *manager_list = NULL;

void add_manager(char *email, char *name, char *password, float salary);

void load_manager_data_from_file(char *filename)
{
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        printf("Could not open file: %s\n", filename);
        return;
    }

    char header[sizeof(MANAGER_DATA_FILE_HEADER)];
    if (fread(header, sizeof(header), 1, file) != 1 || strcmp(header, MANAGER_DATA_FILE_HEADER) != 0)
    {
        printf("Invalid file format: %s\n", filename);
        fclose(file);
        return;
    }

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

    while (fscanf(file, "%s %s %s %s %s %f %f %f %s %f", email, name, password, type, location_geocode, &autonomy, &battery_level, &cost, description, &salary) == 10)
    {
        update_manager_info(email, name, password, type, location_geocode, autonomy, battery_level, cost, description);
    }

    fclose(file);
    printf("Manager data loaded from file: %s\n", filename);
}

void add_manager(char *email, char *name, char *password, float salary)
{
    struct manager *new_manager = (struct manager *)malloc(sizeof(struct manager));
    if (new_manager == NULL)
    {
        printf("Error: could not allocate memory for new manager\n");
        return;
    }
    strcpy(new_manager->email, email);
    strcpy(new_manager->name, name);
    strcpy(new_manager->password, password);
    strcpy(new_manager->type, "");
    strcpy(new_manager->location_geocode, "");
    new_manager->autonomy = 0;
    new_manager->battery_level = 0;
    new_manager->cost = 0;
    strcpy(new_manager->description, "");
    new_manager->salary = salary;
    new_manager->next = NULL;
    if (manager_list == NULL)
    {
        manager_list = new_manager;
    }
    else
    {
        struct manager *last_manager = manager_list;
        while (last_manager->next != NULL)
        {
            last_manager = last_manager->next;
        }
        last_manager->next = new_manager;
    }

    printf("Manager %s added successfully\n", name);
}