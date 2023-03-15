#include <stdio.h>
#include "client.h"
#include "electric_mobility.h"
#include "manager.h"

int main()
{
    int option;

    load_client_data_from_file("client.bin");
    load_electric_mobility_data_from_file("electric_mobility.bin");
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
            add_client();
            break;
        }
        case 2:
        {
            list_clients();
            break;
        }
        case 3:
        {
            add_new_electric_mobility();
            break;
        }
        case 4:
        {
            list_electric_mobility();
            break;
        }
        case 5:
        {
            remove_electric_mobility();
            break;
        }
        case 6:
        {
            list_electric_mobility_by_location();
            break;
        }
        case 7:
        {
            list_electric_mobility_by_autonomy_descending_order();
            break;
        }
        case 8:
        {
            add_new_manager();
            break;
        }
        case 9:
        {
            char email[100];
            printf("E-mail do cliente a alterar: ");
            fgets(email, 100, stdin);
            alter_client_data(email);
            break;
        }
        case 10:
        {
            char email[100];
            printf("E-mail do cliente a remover: ");
            fgets(email, 100, stdin);
            remove_client(email);
            break;
        }
        case 11:
        {
            register_rental();
            break;
        }
        case 12:
        {
            list_electric_mobility_by_autonomy_and_location();
            break;
        }
        case 13:
        {
            char email[100];
            printf("E-mail do gestor a remover: ");
            fgets(email, 100, stdin);
            remove_manager(email);
            break;
        }
        case 14:
        {
            list_managers();
            break;
        }
        case 0:
        {
            break;
        }
        default:
        {
            printf("Opção inválida!\n");
        }
        }
    } while (option != 0);

    save_client_data_to_file("client.bin");
    save_electric_mobility_data_to_file("electric_mobility.bin");
    save_manager_data_to_file("manager.bin");

    return 0;
}