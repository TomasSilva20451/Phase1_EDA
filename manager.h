#ifndef MANAGER_H
#define MANAGER_H

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 50
#define MAX_PASSWORD_LENGTH 50

struct manager {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    float salary;
    struct manager *next;
};

void add_manager(char *email, char *name, char *password, float salary);
struct manager *find_manager_by_email(char *email);
void update_manager_salary(char *email, float new_salary);
void update_manager_info(char *email, char *new_name, char *new_password);
void delete_manager(char *email);

#endif /* MANAGER_H */