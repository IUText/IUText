#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "directories.h"
#include "userlist.h"
#include "files.h"
#include "username_check.h"
#include "userauth.h"
#include "usercred.h"


int main()
{
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
            files();
        }
    }
    else if ( op == 2 ) //LOGIN
    {
        int flag = 0;
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
    }
}
