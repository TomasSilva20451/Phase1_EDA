#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "electric_mobility.h"
#include "client.h"
#include "manager.h"
#include "file_handling.h"
#include "utils.h"
#include "rental.h"
#include "list.h"

// void load_client_data_from_file(const char *filename);
// void load_electric_mobility_data_from_file(const char *filename);
// void add_client(char *name, char *email, int phone_number, int nif);
void list_clients(void);
// void add_new_electric_mobility(char *manufacturer, char *model, char *license_plate, int autonomy, int charging_time, float hourly_price, char *location);
// void list_electric_mobility(void);
// void remove_electric_mobility(char *license_plate);
// void list_electric_mobility_by_location(char *location);
// void list_electric_mobility_by_autonomy(void);
// void update_client_data(int nif, char *new_email, char *new_phone_number);
// void register_rental(int nif, char *license_plate, char *start_date, char *start_time, int duration);
// void list_electric_mobility_by_autonomy_and_location(char *location);
// void remove_manager(char *email);
// void remove_client(char *nif);
// void remove_manager(char *email);
// void remove_client(char *nif);
// void list_managers(void);
// void remove_client(char nif[]);
void save_client_data_to_file(const char *file_name);
// void save_electric_mobility_data_to_file(char *filename);
// void read_electric_mobility_file(char *filename);

int main()
{
    int option;

    // load_client_data_from_file("client.bin");
    // read_electric_mobility_file("electric_mobility.bin");
    // load_manager_data_from_file("manager.bin");

    do
    {
        printf("\n\n");
        printf("1 - Adicionar novo cliente\n");
        printf("2 - Listar clientes\n");
        printf("3 - Adicionar novo veículo elétrico\n");
        printf("4 - Listar veículos elétricos\n");
        printf("5 - Remover veículo elétrico\n");
        printf("6 - Listar veículos elétricos por localização\n");
        printf("7 - Listar veículos elétricos por ordem decrescente da autonomia\n");
        printf("8 - Adicionar novo gestor\n");
        printf("9 - Alterar dados de um cliente\n");
        printf("10 - Remover um cliente\n");
        printf("11 - Registar aluguer\n");
        printf("12 - Listar veículos elétricos por autonomia e por localização\n");
        printf("13 - Remover um gestor\n");
        printf("14 - Listar gestores\n");
        printf("0 - Sair\n\n");

        printf("Escolha uma opção: ");
        scanf("%d", &option);
        getchar();

        switch (option)
        {
        case 1:
        {

            char name[100], email[100], phone_number[20], nif[10];
            printf("Nome: ");
            fgets(name, 100, stdin);
            printf("E-mail: ");
            fgets(email, 100, stdin);
            printf("Número de telefone: ");
            fgets(phone_number, 20, stdin);
            printf("NIF: ");
            fgets(nif, 10, stdin);

            add_client(name, atoi(phone_number), email, atoi(nif));

            // add_client(name, email, atoi(phone_number), atoi(nif));
            break;
        }
        case 2:
        {
            list_clients();
            break;
        }
        case 3:
        {
            int id, stock, battery_level, max_rental_duration, battery_level_per_minute;
            char name[100];
            float price, rent, autonomy;
            printf("ID: ");
            scanf("%d", &id);
            getchar();
            printf("Name: ");
            fgets(name, 100, stdin);
            printf("Price: ");
            scanf("%f", &price);
            getchar();
            printf("Stock: ");
            scanf("%d", &stock);
            getchar();
            printf("Rent: ");
            scanf("%f", &rent);
            getchar();
            printf("Autonomy: ");
            scanf("%f", &autonomy);
            getchar();
            printf("Battery Level: ");
            scanf("%d", &battery_level);
            getchar();
            printf("Max Rental Duration: ");
            scanf("%d", &max_rental_duration);
            getchar();
            printf("Battery Level per Minute: ");
            scanf("%d", &battery_level_per_minute);
            getchar();

            ElectricMobility *em = create_electric_mobility(id, name, price, stock, rent, autonomy, battery_level, max_rental_duration, battery_level_per_minute);
            /
            break;
        }

        case 4:
        {
            // list_electric_mobility();
            break;
        }
        case 5:
        {
            char license_plate[10];
            printf("Matrícula do veículo a remover: ");
            fgets(license_plate, 10, stdin);
            // remove_electric_mobility(license_plate);
            break;
        }
        case 6:
        {
            char location[100];
            printf("Localização dos veículos: ");
            fgets(location, 100, stdin);
            // list_electric_mobility_by_location(location);
            break;
        }
        case 7:
        {
            // list_electric_mobility_by_autonomy();
            break;
        }
        case 8:
        {
            /* char name[100], email[100], password[100];
             char phone_number_str[20];
             float phone_number_float;

             printf("Nome: ");
             fgets(name, 100, stdin);
             printf("E-mail: ");
             fgets(email, 100, stdin);
             printf("Número de telefone: ");
             fgets(phone_number_str, 20, stdin);
             phone_number_float = atof(phone_number_str);
             printf("Password: ");
             fgets(password, 100, stdin);

             char phone_number_str[20];
             snprintf(phone_number_str, 20, "%.2f", phone_number_float);
             add_manager(name, email, phone_number_str, password);
 */ char name[100], email[100], password[100];
            // char *phone_number_char;
            // char *phone_number_char = calloc(20, sizeof(char));

            // int phone_number_int = 0;

            printf("Nome: ");
            fgets(name, 100, stdin);
            printf("E-mail: ");
            fgets(email, 100, stdin);
            printf("Número de telefone: ");
            /* fgets(phone_number_char, 20, stdin);
             phone_number_int = atoi(phone_number_char);*/
            // fgets(phone_number_char, 20, stdin);
            //  phone_number_char[strcspn(phone_number_char, "\n")] = '\0';

            printf("Password: ");
            fgets(password, 100, stdin);

            // add_manager(email, name, password, phone_number_int);

            break;
        }
        case 9:
        {
            char new_email[100], new_phone_number[20];
            // char nif_str[10];
            // int nif;
            /*printf("NIF do cliente a alterar: ");
            fgets(nif_str, 10, stdin);*/
            // nif = atoi(nif_str);
            printf("Novo e-mail: ");
            fgets(new_email, 100, stdin);
            printf("Novo número de telefone: ");
            fgets(new_phone_number, 20, stdin);
            // update_client_data(nif, new_email, new_phone_number);
            break;
        }
        case 10:
        {
            char nif[10];
            printf("NIF do cliente a remover: ");
            fgets(nif, 10, stdin);
            // remove_client(nif);
            break;
        }
        case 11:
        {
            char nif[10], license_plate[10], start_date[20], start_time[20];
            int duration;

            printf("NIF do cliente: ");
            fgets(nif, 10, stdin);
            // int nif_as_int = atoi(nif); // Converter nif para inteiro
            printf("Matrícula do veículo: ");
            fgets(license_plate, 10, stdin);
            printf("Data de início (dd/mm/aaaa): ");
            fgets(start_date, 20, stdin);
            printf("Hora de início (hh:mm): ");
            fgets(start_time, 20, stdin);
            printf("Duração do aluguer (em minutos): ");
            scanf("%d", &duration);
            getchar();
            // register_rental(nif_as_int, license_plate, start_date, start_time, duration); // Passar nif convertido para inteiro
            break;
        }
        case 12:
        {
            char location[100];
            printf("Localização dos veículos: ");
            fgets(location, 100, stdin);
            // list_electric_mobility_by_autonomy_and_location(location);
            break;
        }
        case 13:
        {
            char email[100];
            printf("E-mail do gestor a remover: ");
            fgets(email, 100, stdin);
            // remove_manager(email);
            break;
        }
        case 14:
        {
            // list_managers();
            break;
        }
        case 0:
        {
            // save_client_data_to_file("client.bin");
            // save_electric_mobility_data_to_file("electric_mobility.bin");
            // save_manager_data_to_file("manager.bin");
            printf("A sair...\n");
            break;
        }
        default:
        {
            printf("Opção inválida. Por favor, tente novamente.\n");
            break;
        }
        }
    } while (option != 0);
    return 0;
}