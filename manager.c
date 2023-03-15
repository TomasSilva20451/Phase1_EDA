#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "manager.h"

struct manager *managers_head = NULL;

void add_manager(char *email, char *name, char *password, float salary)
{
    struct manager *new_node = (struct manager *)malloc(sizeof(struct manager));
    strcpy(new_node->email, email);
    strcpy(new_node->name, name);
    strcpy(new_node->password, password);
    new_node->salary = salary;
    new_node->next = managers_head;
    managers_head = new_node;
}

struct manager *find_manager_by_email(char *email)
{
    struct manager *current = managers_head;
    while (current != NULL)
    {
        if (strcmp(current->email, email) == 0)
        {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void delete_manager(char *email)
{
    struct manager *current = managers_head;
    struct manager *previous = NULL;

    while (current != NULL)
    {
        if (strcmp(current->email, email) == 0)
        {
            if (previous == NULL)
            {
                managers_head = current->next;
            }
            else
            {
                previous->next = current->next;
            }
            free(current);
            printf("Manager with email '%s' deleted successfully.\n", email);
            return;
        }
        previous = current;
        current = current->next;
    }

    printf("Error: manager with email '%s' not found.\n", email);
}

void update_manager_info(char *email, char *new_name, char *new_password)
{
    struct manager *manager = find_manager_by_email(email);

    if (manager != NULL)
    {
        strcpy(manager->name, new_name);
        strcpy(manager->password, new_password);
        printf("Manager information updated successfully.\n");
    }
    else
    {
        printf("Error: manager with email '%s' not found.\n", email);
    }
}

void update_manager_salary(char *email, float new_salary)
{
    struct manager *manager = find_manager_by_email(email);

    if (manager != NULL)
    {
        manager->salary = new_salary;
        printf("Manager salary updated successfully.\n");
    }
    else
    {
        printf("Error: manager with email '%s' not found.\n", email);
    }
}

void print_all_managers()
{
    struct manager *current = managers_head;
    printf("%-20s%-16s%-24s%-6s\n", "Email", "Name", "Password", "Salary");
    while (current != NULL)
    {
        printf("%-20s%-16s%-24s%-6.2f\n", current->email, current->name, current->password, current->salary);
        current = current->next;
    }
}