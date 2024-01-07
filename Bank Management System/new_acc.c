

#include "main.h"

void new_acc()
{
    int choice;
    FILE *ptr;
    // Open the file in append+ mode
    ptr = fopen("file.txt", "a+");
    // Label
    account_no:
    system("clear");
    printf("Add the record \n ");
    printf("Enter today's date(mm/dd/yyyy):\n");
    scanf("%d/%d/%d", &add.deposit.month, &add.deposit.day, &add.deposit.year);
    printf("Enter the account number: \n");
    scanf("%d", &check.acc_no);
    // Reading input from the ptr pointer into the format
    // int fscanf(FILE *stream, const char *format, ...)
    while (fscanf(ptr, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone, add.acc_type, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF)
    {
        // Checking if the entered account number already exists or not
        if (check.acc_no == add.acc_no)
        {
            printf("Account no. already in use!");
            // Label
            goto account_no;
        }
    }
    // Storing the account number entered by the user into the add account number
    add.acc_no = check.acc_no;
    // Asking the user to enter the name
    printf("Enter the name: \n");
    scanf("%s", add.name);
    // Asking the user to enter the dob
    printf("Enter the date of birth(mm/dd/yyyy): \n");
    scanf("%d/%d/%d", &add.dob.month, &add.dob.day, &add.dob.year);
    // Asking the user to enter the age
    printf("Enter the age:\n");
    scanf("%d", &add.age);
    // Asking the user to enter the address
    printf("Enter the address:\n");
    scanf("%s", add.address);
    // Asking the user to enter the citizenship number
    printf("Enter the citizenship number:\n");
    scanf("%s", add.citizenship);
    // Asking the user to enter the phone number
    printf("Enter the phone number:\n");
    scanf("%lf", &add.phone);
    // Asking the user to enter the deposit amount
    printf("Enter the amount to deposit:$");
    scanf("%f", &add.amt);
    // Asking the user to enter the type of account
    printf("\nType of account:\n 1)Saving\n 2)#Current\n 3)Fixed1(for 1 year)\n 4)Fixed2(for 2 years)\n 5)Fixed3(for 3 years)\n Enter your choice:\n");
    scanf("%s", add.acc_type);
    // Printing the output into the file pointer ptr
    // int fprintf(FILE *restrict stream, const char *restrict format, ...);
    fprintf(ptr, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);

    // Close the file pointer
    fclose(ptr);
    printf("Account created successfully! \n");
    // Label
    add_invalid:
    printf("Enter 1 to go to the main menu and 0 to exit:\n");
    scanf("%d", &main_exit);
    system("clear");
    if (main_exit == 1)
        menu();
    else if (main_exit == 0)
        exit(0);
    else
    {
        printf("Invalid Option entered \n");
        goto add_invalid;
    }
}
