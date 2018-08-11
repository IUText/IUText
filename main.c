#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "directories.h"
#include "userlist.h"
#include "username_check.h"
#include "userauth.h"
#include "usercred.h"
#include "store_message.h"


int main()
{
    int flag = 0;
    printf("1. Sign up.\n2. Log in.\n");
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
            return;
        }
        else
        {
            printf("Enter password\n");
            scanf(" %s", &password);
            directories(username);
            userlist(username);
            usercred(username, password);
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
            return;
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
            }
            else if ( ( userauth(username, password) ) == 0 )
            {
                flag = 0;
                printf("Password mismatch. Try again.\n");
                return;
            }
        }
        if ( flag == 1 )
        {
            printf("1. Send message.\n2. View message.\n");
            int subop;
            scanf("%d", &subop);
            if ( subop == 2 )
            {
                printf("OOPS. PLACEHOLDER.\n");
                return;
            }
            else if ( subop ==1 )
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
                    return;
                }
                printf("Enter message.\n");
                char text[10000];
                getchar();
                gets(text);
                store_in_sender(sender, receiver, text);
                printf("Done.\n");
            }
        }
    }
}
