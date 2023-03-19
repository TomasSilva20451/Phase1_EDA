// manager.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "manager.h"

#define MANAGER_DATA_FILE_HEADER "MANAGER_DATA_FILE\n"

struct manager *managers_head = NULL;

// add_manager
void add_manager(char *name, char *email, char *password, char *type, char *description, float salary, int phone_number)
{
    struct manager *new_manager = malloc(sizeof(struct manager));
    if (new_manager == NULL)
    {
        printf("Erro ao alocar memória para novo gestor\n");
        return;
    }
    strcpy(new_manager->name, name);
    strcpy(new_manager->email, email);
    strcpy(new_manager->password, password);
    strcpy(new_manager->type, type);
    strcpy(new_manager->description, description);
    new_manager->salary = salary;

    new_manager->phone_number = phone_number;
    new_manager->next = NULL;

    if (managers_head == NULL)
    {
        managers_head = new_manager;
        return;
    }

    struct manager *current = managers_head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = new_manager;
}

/*
int remove_manager(char *email) {
    FILE *fp;
    FILE *temp;
    char buffer[MAX_LINE_SIZE];
    int found = 0;
    int success = 0;

    // open the managers file for reading
    fp = fopen("managers.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open managers file.\n");
        return -1;
    }

    // open a temporary file for writing
    temp = fopen("temp.txt", "w");
    if (temp == NULL) {
        printf("Error: could not create temporary file.\n");
        fclose(fp);
        return -1;
    }

    // read each line of the managers file and write it to the temporary file,
    // except for the line with the manager to be removed
    while (fgets(buffer, MAX_LINE_SIZE, fp) != NULL) {
        if (strstr(buffer, email) == NULL) {
            // this is not the manager to be removed, so write it to the temporary file
            fputs(buffer, temp);
        } else {
            // this is the manager to be removed, so skip it
            found = 1;
        }
    }

    // close both files
    fclose(fp);
    fclose(temp);

    // remove the original managers file and rename the temporary file to take its place
    if (found) {
        if (remove("managers.txt") != 0) {
            printf("Error: could not remove managers file.\n");
            return -1;
        }
        if (rename("temp.txt", "managers.txt") != 0) {
            printf("Error: could not rename temporary file.\n");
            return -1;
        }
        success = 1;
    } else {
        // the manager to be removed was not found
        printf("Error: manager not found.\n");
    }

    return success;
}
*/