#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "directories.h"
#include "userlist.h"
#include "files.h"
#include "username_check.h"
#include "userauth.h"
#include "usercred.h"
#include "store_message.h"

int main()
{
    printf("Enter name of sender.\n");
    char sender[100];
    gets(sender);
    printf("Enter name of receiver.\n");
    char receiver[100];
    gets(receiver);
    printf("Enter message.\n");
    char text[10000];
    gets(text);
    store_in_sender(sender, receiver, text);
    printf("Done.\n");
}
