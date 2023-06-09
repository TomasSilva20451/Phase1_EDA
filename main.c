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

/* Declare function prototype */

// List
void list_clients(void);
int list_mobility();
void list_electric_mobility_by_location(char *location);
void list_electric_mobility_by_autonomy(ElectricMobility *head);
void list_electric_mobility_by_autonomy_and_location(char *location);

// update
void update_client_data(int nif, char *new_email, char *new_phone_number);

// remove
int remove_electric_mobility(char *license_plate);
void remove_client(int nif);
void remove_manager(char *email);

// load and read
Client *load_clients(char *filename);
void read_electric_mobility_file(const char *filename);

// add manager
void add_manager(char *name, char *email, char *password, char *type, char *description, float salary, int phone_number);

int main()
{
    int option;

    // Load files and read
    Client *clients = load_clients("client.bin");
    read_electric_mobility_file("electric_mobility.dat");
    load_manager_data_from_file("manager.bin");

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
        printf("11 - Listar veículos elétricos por autonomia e por localização\n");
        printf("12 - Remover um gestor\n");
        printf("13 - Listar gestores\n");
        printf("0 - Sair\n\n");

        printf("Escolha uma opção: ");
        scanf("%d", &option);
        getchar();

        switch (option)
        {
        case 1:
        {

            /*O trecho de código lê a entrada do usuário para o nome, e-mail, número de telefone e NIF 
            do cliente e,
             em seguida, chama a função add_client() para adicionar o cliente ao sistema. 
             A função add_client() usa o nome, número de telefone, e-mail e NIF do cliente como 
             parâmetros e adiciona um novo cliente ao sistema.

            Parece que o número de telefone e NIF estão sendo convertidos em inteiros usando 
            a função atoi() antes de serem passados para a função add_client(). 
            Isso pode causar problemas se o usuário inserir caracteres não numéricos para esses campos. 
            Pode ser melhor validar a entrada do usuário antes de passá-la para a função add_client().*/
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

            break;
        }
        case 2:
        {
            // code is calling the function list_clients() to display a list of all the clients in the system.
            list_clients();
            break;
        }
        case 3:
        {
            /*Tseu trecho de código está solicitando que o usuário insira valores para os campos de um novo objeto de mobilidade elétrica e
            , em seguida, passe esses valores para a função add_mobility()
             para adicionar o objeto à lista de mobilidades elétricas.

        A função fgets() está sendo usada para ler em cadeias de caracteres do 
        fluxo de entrada padrão, e as funções atoi() e atof() estão sendo usadas 
        para converter essas cadeias de caracteres em seus valores inteiros e flutuantes
         correspondentes, respectivamente.

        No geral, este trecho de código é responsável por adicionar novos objetos 
        de mobilidade elétrica ao sistema.*/
            char id[100], name[100], license_plate[10], location[100], price[100], stock[100], rent[100], autonomy[100], battery_level[100];

            printf("ID: ");
            fgets(id, 100, stdin);
            printf("Name: ");
            fgets(name, 100, stdin);
            printf("License plate: ");
            fgets(license_plate, 10, stdin);
            printf("Location: ");
            fgets(location, 100, stdin);
            printf("Price: ");
            fgets(price, 100, stdin);
            printf("Stock: ");
            fgets(stock, 100, stdin);
            printf("Rent: ");
            fgets(rent, 100, stdin);
            printf("Autonomy: ");
            fgets(autonomy, 100, stdin);
            printf("Battery Level: ");
            fgets(battery_level, 100, stdin);

            add_mobility(atoi(id), name, license_plate, location, atof(price), atoi(stock), atof(rent), atof(autonomy), atoi(battery_level));

            break;
        }
        case 4:
        {
            /*This code is calling the function list_mobility() which lists all the electric mobility i
            tems in the inventory. This is part of a larger program that likely has a menu or 
            interface for managing an electric mobility rental service. By calling this function 
            in response to user input (presumably selecting a menu option), the program displays 
            the current inventory of electric mobility items to the user. The break; statement
             is used to exit the current switch-case block and continue executing the rest of the program.*/
            list_mobility();
            break;
        }

        case 5:
        {
            /*This code prompts the user to enter a license plate and then attempts to
             remove the electric mobility with that license plate from the system 
             by calling the remove_electric_mobility function. If the function call
              returns a non-zero value, it indicates that the mobility was successfully 
              removed, and the program prints a success message. If the function call returns
               zero, it indicates that the mobility was not found or could not be removed,
                and the program prints a failure message.*/
            char license_plate[10];
            printf("Matrícula do veículo a remover: ");
            fgets(license_plate, 10, stdin);
            int remove_electric_mobility(char *license_plate);

            int success = remove_electric_mobility(license_plate);
            if (success)
            {
                printf("Electric mobility with license plate %s has been removed.\n", license_plate);
            }
            else
            {
                printf("Failed to remove electric mobility with license plate %s.\n", license_plate);
            }
            break;
        }
        case 6:
        {

            /*This code snippet prompts the user to input a location and then calls the list_electric_mobility_by_location function with the provided location as an argument. This function will then search the electric mobility linked list for all mobility items located in the specified location and print their details to the console. Finally, the break statement is used to exit the switch statement and return to the main menu.*/
            char location[100];
            printf("Localização dos veículos: ");
            fgets(location, 100, stdin);
            list_electric_mobility_by_location(location);
            break;
        }
        case 7:
        {
            /*This code snippet declares a pointer variable called head of type ElectricMobility and initializes it to NULL. Then, it calls the list_electric_mobility_by_autonomy function and passes the head variable as an argument. This function will iterate over all the electric mobility items in the linked list, calculate the total autonomy of each item, and print out the items sorted by their total autonomy. 
            Finally, the break statement ends the current case and returns to the main menu.*/
            ElectricMobility *head = NULL;
            list_electric_mobility_by_autonomy(head);
            break;
        }
        case 8:
        {
            /*This is a block of code that prompts the user to input information about a new manager, and then calls the function "add_manager" to add the manager to the system with the given information. The information collected includes the manager's name, email, password, job type, job description, salary, and phone number.*/
            char name[50], email[100], password[20], type[100], description[100], salary[100], phone_number[15];
            printf("Nome: ");
            fgets(name, 50, stdin);
            printf("E-mail: ");
            fgets(email, 100, stdin);
            printf("Password: ");
            fgets(password, 20, stdin);
            printf("Type: ");
            fgets(type, 100, stdin);
            printf("Description: ");
            fgets(description, 100, stdin);
            printf("Salary: ");
            fgets(salary, 100, stdin);
            printf("Número de telefone: ");
            fgets(phone_number, 15, stdin);

            add_manager(name, email, password, type, description, atof(salary), atoi(phone_number));

            break;
        }
        case 9:
        {
            /*This code prompts the user to enter the NIF (Portuguese tax identification number) of the client they want to update, as well as the new email and phone number for that client. It then calls the function update_client_data() with the provided parameters to update the client's information.*/
            char new_email[100], new_phone_number[20];
            char nif_str[10];
            int nif;
            printf("NIF do cliente a alterar: ");
            fgets(nif_str, 10, stdin);
            nif = atoi(nif_str);
            printf("Novo e-mail: ");
            fgets(new_email, 100, stdin);
            printf("Novo número de telefone: ");
            fgets(new_phone_number, 20, stdin);
            update_client_data(nif, new_email, new_phone_number);
            break;
        }
        case 10:
        {
            /*This code block prompts the user to input a client's NIF, then calls the remove_client function with the given NIF as a parameter to remove the client from the system. If the removal is successful, a message is printed to confirm it.*/
            int nif;
            printf("NIF do cliente a remover: ");
            scanf("%d", &nif);

            void remove_client(int nif);
            remove_client(nif);

            printf("Cliente com NIF %d foi removido.\n", nif);

            break;
        }
        case 11:
        {
            char location[100];
            printf("Localização dos veículos: ");
            fgets(location, 100, stdin);
            list_electric_mobility_by_autonomy_and_location(location);
            break;
        }
        case 12:
        {
            char email[100];
            printf("E-mail do gestor a remover: ");
            fgets(email, 100, stdin);
            remove_manager(email);
            break;
        }
        case 13:
        {
            list_manager();
            break;
        }
        case 0:
        {
            /*The first line, save_client_data_to_file("client.bin"), is likely calling a function that saves client data to a file named "client.bin". The exact implementation of this function is not clear from the code snippet, but it could involve iterating over a list of client objects and writing each one's data to the file.

The second line, save_electric_mobility_data_to_file("electric_mobility.bin"), is probably calling a similar function that saves data related to electric mobility (possibly vehicle information) to a file named "electric_mobility.bin".

The third line, save_manager_data_to_file("manager.dat"), may be calling a function that saves data related to a manager or management system to a file named "manager.dat". Again, the exact implementation of this function is not clear from the code snippet.

Overall, these three lines of code seem to be part of a larger program that involves storing and managing data related to clients, electric mobility, and management.*/
            save_client_data_to_file("client.bin");
            save_electric_mobility_data_to_file("electric_mobility.bin");
            save_manager_data_to_file("manager.dat");

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

/*
Aluguer deixar para melhorar na fase 2

printf("11 - Registar aluguer\n");

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
*/