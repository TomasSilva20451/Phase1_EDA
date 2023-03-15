#include <stdio.h>
#include "manager.h"
#include "client.h"
#include "vehicle.h"

int main()
{
    load_manager_data_from_file("manager.bin");

    int option = 0;
    do
    {
        printf("\n\n");
        printf("1. Adicionar um novo veiculo\n");
        printf("2. Adicionar um novo cliente\n");
        printf("3. Adicionar um novo aluguer\n");
        printf("4. Listar todos os veiculos\n");
        printf("5. Listar todos os clientes\n");
        printf("6. Listar todos os alugueres\n");
        printf("7. Remover um veiculo\n");
        printf("8. Remover um cliente\n");
        printf("9. Alterar os dados de um cliente\n");
        printf("10. Registar um aluguer\n");
        printf("11. Listar todos os veiculos eletricos ordenados por autonomia decrescente\n");
        printf("12. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &option);
        getchar();

        switch (option)
        {
        case 1:
        {
            add_vehicle();
            break;
        }
        case 2:
        {
            add_client();
            break;
        }
        case 3:
        {
            add_rental();
            break;
        }
        case 4:
        {
            list_all_vehicles();
            break;
        }
        case 5:
        {
            list_all_clients();
            break;
        }
        case 6:
        {
            list_all_rentals();
            break;
        }
        case 7:
        {
            remove_vehicle();
            break;
        }
        case 8:
        {
            remove_client();
            break;
        }
        case 9:
        {
            char email[100];
            printf("E-mail do cliente a alterar: ");
            fgets(email, 100, stdin);
            email[strcspn(email, "\n")] = 0;
            alter_client_data(email);
            break;
        }
        case 10:
        {
            register_rental();
            break;
        }
        case 11:
        {
            list_electric_mobility_by_autonomy_descending_order();
            break;
        }
        case 12:
        {
            save_manager_data_to_file("manager.bin");
            printf("Ate a proxima!\n");
            break;
        }
        default:
        {
            printf("Opcao invalida.\n");
        }
        }
    } while (option != 12);

    return 0;
}