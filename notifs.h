void newnotifs(char* sender, char* receiver)
{
    char direct[1000];
    strcpy(direct, receiver);
    strcat(direct, "/notifs.txt");
//    printf("Notif file = %s\n", direct);
    FILE *f;
    f = fopen(direct, "a");
    fprintf(f, "%s\n", sender); //add an entry of the name of the sender where the sender is username
    fclose(f);
}

void viewnotifs(char* username)
{
    char direct[1000];
    strcpy(direct, username);
    strcat(direct, "/notifs.txt");
//    printf("Notif file = %s\n", direct);
    FILE *f;
    f = fopen(direct, "r");
    while ( !feof(f) )
    {
        printf("%c", fgetc(f));
    }
    printf("\n");
}

void notifsdel(char* username)
{
    char direct[1000];
    strcpy(direct, username);
    strcat(direct, "/notifs.txt");
//    printf("Notif file = %s\n", direct);
    FILE *f;
    f = fopen(direct, "w");
//    while ( !feof(f) )
//    {
//        fputc(NULL, f);
//    }
    fclose(f);
}
