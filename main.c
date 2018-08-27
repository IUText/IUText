#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "directories.h"
#include "userlist.h"
#include "username_check.h"
#include "userauth.h"
#include "usercred.h"
#include "store_message.h"
#include "view_message.h"
#include "encrypt.h"

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

int main()
{
    printf(" ___                              ___         ___                     ___  \n");
    printf("  |            |   |               |         |            \\ /          |   \n");
    printf("  +            |   |               +         |-+-          +           +   \n");
    printf("  |            |   |               |         |            / \\          |   \n");
    printf(" ---            ---                           ---                          \n");
    printf("                                                                        \n");
    printf("\nEnter any key to continue...\n");
    int c = getchar();
    system(CLEAR);
    while (1)
    {
        int flag = 0;
        printf("1. Sign up.\n2. Log in.\n3. Exit.\n");
        int op;
        scanf("%d", &op);
        if ( op == 1 ) // SIGN UP
        {
            char username[100];
            char password[100];
            printf("Enter username.\n");
            scanf(" %s", &username);
            if ( ( username_check(username) ) == 1 )
            {
                printf("Username taken. Please try again.\n");
                int z = getchar();
                printf("Enter any key to continue...\n");
                int c = getchar();
                system(CLEAR);
            }
            else
            {
                printf("Enter password\n");
                scanf(" %s", &password);
                directories(username);
                userlist(username);
                usercred(username, password);
                printf("Account for %s created.\n", username);
                int z = getchar();
                printf("Enter any key to continue...\n");
                int c = getchar();
                system(CLEAR);
            }
        }
        else if ( op == 2 ) //LOGIN
        {
            char username[100];
            char password[100];
            printf("Enter username\n");
            scanf(" %s", &username);
            if ( username_check(username) == 0 )
            {
                printf("Username doesn't exist. Try again.\n");
            }
            else if  ( ( username_check(username) ) == 1 )
            {
                printf("Username found in userlist.txt.\n");
                printf("Please enter password.\n");
                scanf(" %s", &password);
                if ( ( userauth(username, password) ) == 1 )
                {
                    flag = 1;
                    printf("Logged in to user: %s\n", username);
                    int z = getchar();
                    printf("Enter any key to continue...\n");
                    int c = getchar();
                    system(CLEAR);
                }
                else if ( ( userauth(username, password) ) == 0 )
                {
                    flag = 0;
                    printf("Password mismatch. Try again.\n");
                    int z = getchar();
                    printf("Enter any key to continue...\n");
                    int c = getchar();
                    system(CLEAR);
                }
            }
            if ( flag == 1 )
            {
                while(1)
                {
                    printf("1. Send message.\n2. View message.\n3. Logout.\n");
                    int subop;
                    scanf("%d", &subop);
                    if ( subop == 2 )
                    {
                        printf("Enter name of user whose messages you want to view.\n");
                        char toview[100];
                        scanf(" %s", &toview);
                        view_messages(username, toview);
                        int z = getchar();
                        printf("Enter any key to continue...\n");
                        int c = getchar();
                        system(CLEAR);
                    }
                    else if ( subop == 1 )
                    {
                        char sender[100];
                        strcpy(sender, username);
                        printf("Enter name of receiver.\n");
                        char receiver[100];
                        scanf(" %s", receiver);
                        if ( ( username_check(receiver) ) == 1 )
                        {
                            printf("Receiver found.\n");
                        }
                        else
                        {
                            printf("Receiver not found in list of users. Try again.\n");
                            int z = getchar();
                            printf("Enter any key to continue...\n");
                            int c = getchar();
                            system(CLEAR);
                        }
                        printf("Enter message.\n");
                        char text[10000];
                        getchar();
                        gets(text);
                        store_in_sender(sender, receiver, text);
                        printf("Done.\n");
                        printf("Enter any key to continue...\n");
                        int c = getchar();
                        system(CLEAR);
                    }
                    else if ( subop == 3 )
                    {
                        system(CLEAR);
                        break;
                    }
                }
            }
        }
        else if ( op == 3 )
        {
            break;
        }
    }
}
