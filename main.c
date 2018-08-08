#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "directories.h"
#include "userlist.h"
#include "files.h"

int main()
{
    printf("1. Sign up.\n2. Log in.\n");
    int op;
    scanf("%d", &op);
    if ( op == 1 )
    {
        char username[100];
        printf("Enter username\n");
        gets(username);
        if ( duplicate_checker(username) == 0 ) /*DEPENDS ON DUPLICATE_CHECKER FUNCTION RETURN VALUE */
        {
            printf("Username taken. Please try again.\n");
            return;
        }
        else
        {
            directories(username);
            userlist(username);
            files();
        }
    }
    else if ( op == 2 )
    {
        char username[100];
        printf("Enter username\n");
        gets(username);
        /* USERAUTH HERE */
    }
}
