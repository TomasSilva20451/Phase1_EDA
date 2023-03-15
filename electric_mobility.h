#ifndef ELECTRIC_MOBILITY_H
#define ELECTRIC_MOBILITY_H

struct electric_mobility
{
    char license_plate[9];
    char *type;
    char *model;
    char *manufacturer;
    char *power_source;
    int max_speed;
    float autonomy;
    float price;
    float battery_level;
    struct electric_mobility *next;
};

struct electric_mobility *get_electric_mobility_head();
void add_electric_mobility(char *license_plate, char *type, char *model, char *manufacturer, char *power_source, int max_speed, float autonomy, float price, float battery_level);
void print_all_electric_mobility();
void update_electric_mobility_battery_level(char *license_plate, float battery_level);
void delete_electric_mobility(char *license_plate);
void add_new_electric_mobility(char *license_plate);
int find_electric_mobility_index(char *license_plate);
void save_electric_mobility_data_to_file(char *filename);
void load_electric_mobility_data_from_file(char *filename);

#endif /* ELECTRIC_MOBILITY_H */