/* files.h: Create individual user files for storing texts. No duplicates generated. */

void files()
{
    FILE *f;
    f = fopen("userlist.txt", "r");
    char c;
    char userlist[100][100];
    /* Initialise userlist with NULL */
    int i, j;
    int row = 0, column = 0;
    while ( ( c = fgetc(f) ) != EOF )
    {
        if ( c == 32 )
        {
            userlist[row][column] = NULL;
            row++;
            column = 0;
        }
        else
        {
            userlist[row][column] = c;
            column++;
        }
    }
    fclose(f);
    /* NULL-ify the end of the userlist array */
    for ( i = row ; i < 100 ; i++ )
    {
        userlist[i][0] = NULL;
    }
    for ( i = 0 ; userlist[i][0] != NULL ; i++ )
    {
        char temp[100] = "";
        strcpy(temp, userlist[i]);
        printf("Detected username: %s. Going into %s folder.\n", temp, temp);
        chdir(temp);
        printf("Successfully entered %s folder.\n", temp);
        system("pwd");
        /* FIXED */
        for ( j = 0 ; userlist[j][0] != NULL ; j++ )
        {
            printf("Comparison with ");
            puts(userlist[j]);
            char tempfile[100] = "";
            strcpy(tempfile, userlist[j]);
            if ( ( strcmp(tempfile, userlist[i]) ) == 0 )
            {
                printf("Same username. Skipping.\n");
                continue;
            }
            else
            {
                strcat(tempfile, ".txt");
                FILE *z;
                z = fopen(tempfile, "a");
                fclose(z);
                printf("Creating %s file in %s folder successful\n", tempfile, temp);
            }
        }
        printf("Entering root directory.\n");
        chdir("..");
        system("pwd");
        printf("Exiting loop.\n");
    }
}
