// managers.h
#ifndef MANAGERS_H
#define MANAGERS_H

typedef struct
{
    char name[50];
    char NIF[50];
    char address[50];
} Managers;

void insert_managers_data(Managers *managers);
void remove_managers_data(Managers *managers);
void change_managers_data(Managers *managers);

#endif