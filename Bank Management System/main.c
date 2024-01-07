#include "main.h"
//To enter the program, you need to enter password which is "password"




int main_exit;

int main()
{
    char pass[10], password[10] = "password";

    printf("Enter the password to login: \n");
    scanf("%s", pass);

    // Comparing whether the password entered by the user matches the password stored
    if (strcmp(pass, password) == 0)
    {
        printf("Password has been matched successfully \n");
        // Clearing the screen
        system("clear");
        // Calling the menu function
        menu();
    }
    else
    {
        printf("Wrong Password has been entered \n");
        // Prompt option to retry again
        printf("Enter 1 to try again and 0 to exit: \n");
        scanf("%d", &main_exit);

        if (main_exit == 1)
        {
            system("clear");
            main();
        }
        else if (main_exit == 0)
        {
            printf("Exiting the Program...... \n");
        }
    }

    return 0;
}
