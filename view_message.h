void view_messages(char* username, char* toview)
{
    char command[1000];
    strcpy(command, username);
    strcat(command, "/");
    strcat(command, toview);
    strcat(command, ".txt");
    puts(command);
    FILE *f;
    f = fopen(command, "r");
    while ( !feof(f) )
    {
        char c;
        c = fgetc(f);
        if ( c == 10)
            printf("%c", c);
        else
            printf("%c", c+2);
    }
    //printf("END OF TEXT MESSAGES.\n");
    fclose(f);
}
