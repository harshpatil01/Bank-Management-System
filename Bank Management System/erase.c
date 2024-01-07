#include "main.h"

void erase(void)
{
    FILE *old, *newrec;
    int test = 0;

    old = fopen("file.txt", "r");
    newrec = fopen("new.txt", "w");

    // Asking the user which account details he wants to delete
    printf("Enter the account no. of the customer you want to delete:");
    scanf("%d", &rem.acc_no);

    // Reading input from the ptr pointer into the format
    while (fscanf(old, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone, add.acc_type, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF)
    {
        // If the entered account does not match the record
        if (add.acc_no != rem.acc_no)
        {
            // Printing the output into the file pointer ptr
            fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
        }
        else
        {
            test++;
            printf("Record deleted successfully! \n");
        }
    }

    // Close the old file
    fclose(old);
    // Close the new file
    fclose(newrec);
    // Removing the old file
    remove("file.txt");
    // Renaming the new file with the old file name
    rename("new.txt", "file.txt");

    // If there are no records found
    if (test == 0)
    {
        printf("Record not found!! \n");
    erase_invalid:
        printf("Enter 0 to try again, 1 to return to the main menu, and 2 to exit: \n");
        scanf("%d", &main_exit);

        if (main_exit == 1)
            menu();
        else if (main_exit == 2)
            close_program();
        else if (main_exit == 0)
            erase();
        else
        {
            printf("Invalid! \n");
            goto erase_invalid;
        }
    }
    else
    {
        printf("Enter 1 to go to the main menu and 0 to exit:");
        scanf("%d", &main_exit);
        system("clear");

        if (main_exit == 1)
            menu();
        else
            close_program();
    }
}
