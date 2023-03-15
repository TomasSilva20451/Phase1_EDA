#ifndef MANAGER_H
#define MANAGER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODE_LENGTH 10
#define MAX_LOCATION_LENGTH 20
#define MAX_TYPE_LENGTH 20
#define MAX_DESCRIPTION_LENGTH 100

struct manager {
    char code[MAX_CODE_LENGTH];
    char location_geocode[MAX_LOCATION_LENGTH];
    char type[MAX_TYPE_LENGTH];
    float autonomy;
    float battery_level;
    float cost;
    char description[MAX_DESCRIPTION_LENGTH];
};

extern struct manager *managers_head;

void load_managers(char *file_path);
void save_managers(char *file_path);
void insert_manager(struct manager new_manager);
void remove_manager(char *code);
void update_manager_info(char *code, char *new_location_geocode, char *new_type, float new_autonomy, float new_battery_level, float new_cost, char *new_description);
void list_all_managers();
struct manager *find_manager_by_code(char *code);
void list_electric_mobility_by_location(char *geocode);

#endif /* MANAGER_H */
