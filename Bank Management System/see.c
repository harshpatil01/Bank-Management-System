#include "main.h"

void see(void)
{
    FILE *ptr;
    int test = 0, rate;
    int choice;
    float time;
    float intrst;

    ptr = fopen("file.txt", "r");

    printf("Do you want to check by\n 1.Account no\n 2.Name\n Enter your choice: \n");
    scanf("%d", &choice);

    if (choice == 1)
    {
        printf("Enter the account number: \n");
        scanf("%d", &check.acc_no);

        while (fscanf(ptr, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone, add.acc_type, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF)
        {
            if (add.acc_no == check.acc_no)
            {
                system("clear");
                test = 1;
                printf("\nAccount NO.:%d\nName:%s \nDOB:%d/%d/%d \nAge:%d \nAddress:%s \nCitizenship No:%s \nPhone number:%.0lf \nType Of Account:%s \nAmount deposited:$ %.2f \nDate Of Deposit:%d/%d/%d\n\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone,
                       add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);

                if (strcmp(add.acc_type, "fixed1") == 0)
                {
                    time = 1.0;
                    rate = 9;
                    intrst = calculateInterest(time, add.amt, rate);
                    printf("\n\nYou will get $%.2f as interest on %d/%d/%d", intrst, add.deposit.month, add.deposit.day, add.deposit.year + 1);
                }
                else if (strcmp(add.acc_type, "fixed2") == 0)
                {
                    time = 2.0;
                    rate = 11;
                    intrst = calculateInterest(time, add.amt, rate);
                    printf("\n\nYou will get $.%.2f as interest on %d/%d/%d", intrst, add.deposit.month, add.deposit.day, add.deposit.year + 2);
                }
                else if (strcmp(add.acc_type, "fixed3") == 0)
                {
                    time = 3.0;
                    rate = 13;
                    intrst = calculateInterest(time, add.amt, rate);
                    printf("\n\nYou will get $.%.2f as interest on %d/%d/%d", intrst, add.deposit.month, add.deposit.day, add.deposit.year + 3);
                }
                else if (strcmp(add.acc_type, "saving") == 0)
                {
                    time = (1.0 / 12.0);
                    rate = 8;
                    intrst = calculateInterest(time, add.amt, rate);
                    printf("\n\nYou will get $.%.2f as interest on %d of every month", intrst, add.deposit.day);
                }
                else if (strcmp(add.acc_type, "current") == 0)
                {
                    printf("You will get no interest \n");
                }
            }
        }
    }
    else if (choice == 2)
    {
        printf("Enter the name: ");
        scanf("%s", check.name);

        while (fscanf(ptr, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone, add.acc_type, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF)
        {
            if (strcmp(add.name, check.name) == 0)
            {
                system("clear");
                test = 1;
                printf("\nAccount No.:%d\nName:%s \nDOB:%d/%d/%d \nAge:%d \nAddress:%s \nCitizenship No:%s \nPhone number:%.0lf \nType Of Account:%s \nAmount deposited:$%.2f \nDate Of Deposit:%d/%d/%d\n\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone,
                       add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);

                if (strcmp(add.acc_type, "fixed1") == 0)
                {
                    time = 1.0;
                    rate = 9;
                    intrst = calculateInterest(time, add.amt, rate);
                    printf("\n\nYou will get $.%.2f as interest on %d/%d/%d", intrst, add.deposit.month, add.deposit.day, add.deposit.year + 1);
                }
                else if (strcmp(add.acc_type, "fixed2") == 0)
                {
                    time = 2.0;
                    rate = 11;
                    intrst = calculateInterest(time, add.amt, rate);
                    printf("\n\nYou will get $.%.2f as interest on %d/%d/%d", intrst, add.deposit.month, add.deposit.day, add.deposit.year + 2);
                }
                else if (strcmp(add.acc_type, "fixed3") ==0)
                {
                    time = 3.0;
                    rate = 13;
                    intrst = calculateInterest(time, add.amt, rate);
                    printf("\n\nYou will get $.%.2f as interest on %d/%d/%d", intrst, add.deposit.month, add.deposit.day, add.deposit.year + 3);
                }
                else if (strcmp(add.acc_type, "saving") == 0)
                {
                    time = (1.0 / 12.0);
                    rate = 8;
                    intrst = calculateInterest(time, add.amt, rate);
                    printf("\n\nYou will get $.%.2f as interest on %d of every month", intrst, add.deposit.day);
                }
                else if (strcmp(add.acc_type, "current") == 0)
                {
                    printf("You will get no interest \n");
                }
            }
        }
    }

    fclose(ptr);

    if (test != 1)
    {
        system("clear");
        printf("Record not found!! \n");
    }

    see_invalid:
    printf("Enter 0 to try again, 1 to return to the main menu, and 2 to exit\n");
    // Add the closing brace for the see function
}
