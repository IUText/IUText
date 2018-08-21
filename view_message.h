void view_messages(char* username, char* toview)
{
    char command[1000];
    strcat(command, username);
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
        printf("%c", c);
    }
    printf("END OF TEXT MESSAGES.\n");
    fclose(f);
}
