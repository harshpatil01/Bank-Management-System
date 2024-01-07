


#include "main.h"

void menu(void)
{
    int choice;
    system("clear");
    printf("\n \t CUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM \t \n ");
    printf("\tMAIN MENU \t \n");
    printf("\n\t1. Create new account\n\t2. Update the information of an existing account\n\t3. Perform transactions\n\t4. Check the details of an existing account\n\t5. Remove an existing account\n\t6. View customer's list\n\t7. Exit\n\t Enter your choice :\n");
    scanf("%d", &choice);

    system("clear");
    switch (choice)
    {
        // Calling the function
        case 1:
            new_acc();
            break;
        case 2:
            edit();
            break;
        case 3:
            transact();
            break;
        case 4:
            see();
            break;
        case 5:
            erase();
            break;
        case 6:
            view_list();
            break;
        case 7:
            close_program();
            break;
        default:
            printf("Invalid choice! Please enter a valid option.\n");
            break;
    }
}
