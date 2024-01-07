



#include <unistd.h>
#include "main.h"


void transact(void)
{
    int choice, test = 0;
    FILE *old, *newrec;
    old = fopen("file.txt", "r");
    newrec = fopen("new.txt", "w");

    // Asking the user to enter the account number
    printf("Enter the account no. of the customer:");
    scanf("%d", &transaction.acc_no);

    // Reading input from the stream file pointer into the format
    // int fscanf(FILE *stream, const char *format, ...)
    while (fscanf(old, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone, add.acc_type, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF)
    {
        // If the account number matches the account number entered by the user
        if (add.acc_no == transaction.acc_no)
        {
            test = 1;

            // Comparing which type of account it is
            if (strcmp(add.acc_type, "fixed1") == 0 || strcmp(add.acc_type, "fixed2") == 0 || strcmp(add.acc_type, "fixed3") == 0)
            {
                printf("YOU CANNOT DEPOSIT OR WITHDRAW CASH IN FIXED ACCOUNTS!!!!! \n");
                sleep(2);
                system("clear");
                menu();
            }
            else
            {
                // Asking the user to deposit and withdraw
                printf("Do you want to\n1. Deposit\n2. Withdraw?\nEnter your choice(1 for deposit and 2 for withdraw):");
                scanf("%d", &choice);

                // If the user enters the option 1 for deposit
                if (choice == 1)
                {
                    // Asking the user how much he wants to deposit
                    printf("Enter the amount you want to deposit:$ ");
                    scanf("%f", &transaction.amt);

                    // Adding the amount to the total amount of the deposit
                    add.amt += transaction.amt;
                    printf("Money deposit successful! \n");
                }
                else if (choice == 2)
                {
                    // Asking the user how much he wants to withdraw
                    printf("Enter the amount you want to withdraw:$ ");
                    scanf("%f", &transaction.amt);

                    // Subtracting the amount entered by the user from the total amount
                    add.amt -= transaction.amt;
                    printf("Money withdrawal successful \n");
                }

                // Printing the output into the file pointer ptr
                // int fprintf(FILE *restrict stream, const char *restrict format, ...);
                fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
            }
        }
        else
        {
            // Printing the output into the file pointer ptr
            // int fprintf(FILE *restrict stream, const char *restrict format, ...);
            fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
        }
    }

    // Close the old file
    fclose(old);
    // Close the new file
    fclose(newrec);

    // Remove the old file
    remove("file.txt");
    // Rename the new file with the old file name
    rename("new.txt", "file.txt");

    if (test != 1)
    {
        printf("Record not found!! \n");
    transact_invalid:
        printf("Enter 0 to try again, 1 to return to the main menu, and 2 to exit: \n");
        scanf("%d", &main_exit);
        system("clear");

        if (main_exit == 0)
            transact();
        else if (main_exit == 1)
            menu();
        else if (main_exit == 2)
            exit(0);
        else
        {
            printf("Invalid! \n");
            goto transact_invalid;
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
            exit(0);
    }
}
