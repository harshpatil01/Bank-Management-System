

#include "main.h"

void view_list()
{
    FILE *view;
    view = fopen("file.txt", "r");
    int test = 0;
    system("clear");
    printf("\nACC. NO.\tNAME\t\t\tADDRESS\t\t\tPHONE\n");
    // Reading input from the ptr pointer into the format
    // int fscanf(FILE *stream, const char *format, ...)
    while (fscanf(view, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone, add.acc_type, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF)
    {
        printf("\n%6d\t %10s\t\t\t%10s\t\t%.0lf", add.acc_no, add.name, add.address, add.phone);
        test++;
    }

    fclose(view);
    // If no records are found
    if (test == 0)
    {
        system("clear");
        printf("NO RECORDS!!\n");
    }
    view_list_invalid:
    printf("Enter 1 to go to the main menu and 0 to exit: \n");
    scanf("%d", &main_exit);
    system("clear");
    if (main_exit == 1)
        menu();
    else if (main_exit == 0)
        close_program();
    else
    {
        printf("Invalid Option has been entered \n");
        goto view_list_invalid;
    }
}
