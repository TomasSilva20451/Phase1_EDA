#ifndef ELECTRIC_MOBILITY_H
#define ELECTRIC_MOBILITY_H

struct electric_mobility {
    char id[10];
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
void add_electric_mobility(char *id, char *type, char *model, char *manufacturer, char *power_source, int max_speed, float autonomy, float price, float battery_level);
void print_all_electric_mobility();
void update_battery_level(char *id, float battery_level);
void delete_electric_mobility(char *id);

#endif