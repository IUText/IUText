/* userauth.h: To check whether username and password match from usercred.txt during login */

int userauth(char *username, char *password)
{
    int flag;
    FILE *f;
    f = fopen("usercred.txt", "r");
    while ( !feof(f) )
    {
        char tempuser[100];
        char temppass[100];
        fscanf(f, "%s %s", &tempuser, &temppass);
        //printf("Comparison in username between %s, and %s.\n", username, tempuser);
        //printf("Comparison in password between %s, and %s.\n", password, temppass);
        /*if ( ( ( ( strcmp(tempuser, username) ) == 0 ) && ( strcmp(tempuser, username) ) == 0 ) )
        {
            flag = 1;
            break;
        }
        else
        {
            flag = 0;
        }*/
        if ( ( strcmp(username, tempuser) ) == 0 )
        {
            if ( ( strcmp(password, temppass) ) == 0 )
            {
                flag=1;
                //printf("Username and password match. Flag = %d\n", flag);
                break;
            }
            else
            {
                flag = 0;
                //printf("Username and password do not match. Flag = %d\n", flag);
            }
        }
        else
        {
            flag = 0;
            //printf("Username and password do not match. Flag = %d\n", flag);
        }
        int i;
        for ( i = 0 ; tempuser[i] != NULL ; i++ )
        {
            tempuser[i] = NULL;
        }
        for ( i = 0 ; tempuser[i] != NULL ; i++ )
        {
            temppass[i] = NULL;
        }
    }
    fclose(f);
    return flag;
}
