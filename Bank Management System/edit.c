#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void edit(void)
{
    int choice, test = 0;
    FILE *old, *newrec;
    old = fopen("file.txt", "r");
    newrec = fopen("new.txt", "w");

    printf("Enter the account no. of the customer whose info you want to change:\n");
    scanf("%d", &upd.acc_no);

    while (fscanf(old, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone, add.acc_type, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF)
    {
        if (add.acc_no == upd.acc_no)
        {
            test = 1;
            printf("\nWhich information do you want to change?\n 1.Address\n 2.Phone\n Enter your choice(1 for address and 2 for phone):");
            scanf("%d", &choice);
            system("clear");

            if (choice == 1)
            {
                printf("Enter the new address: \n");
                scanf("%s", upd.address);
                fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, upd.address, add.citizenship, add.phone, add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
                system("clear");
                printf("Changes have been saved! \n");
            }
            else if (choice == 2)
            {
                printf("Enter the new phone number:");
                scanf("%lf", &upd.phone);
                fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, upd.phone, add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
                system("clear");
                printf("Changes have been saved! \n");
            }
        }
        else
        {
            fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
        }
    }

    fclose(old);
    fclose(newrec);
    remove("file.txt");
    rename("new.txt", "file.txt");

    if (test != 1)
    {
        system("clear");
        printf(" Record not found!! \n");

    edit_invalid:
        printf("Enter 0 to try again, 1 to return to the main menu, and 2 to exit:\n");
        scanf("%d", &main_exit);
        system("clear");

        if (main_exit == 1)
            menu();
        else if (main_exit == 2)
            close_program();
        else if (main_exit == 0)
            edit();
        else
        {
            printf("Invalid! \n");
            goto edit_invalid;
        }
    }
    else
    {
        printf("Enter 1 to go to the main menu and 0 to exit: \n");
        scanf("%d", &main_exit);
        system("clear");

        if (main_exit == 1)
            menu();
        else
            close_program();
    }
}
