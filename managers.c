// managers.c
#include "managers.h"

// Insert new managers data
void insert_managers_data(Managers *managers)
{
    strcpy(managers->name, "Name");
    strcpy(managers->NIF, "NIF");
    strcpy(managers->address, "Address");
}

// Remove certain managers data
void remove_managers_data(Managers *managers)
{
    strcpy(managers->name, "");
    strcpy(managers->NIF, "");
    strcpy(managers->address, "");
}

// Change certain managers data
void change_managers_data(Managers *managers)
{
    strcpy(managers->name, "New Name");
    strcpy(managers->NIF, "New NIF");
    strcpy(managers->address, "New Address");
}
