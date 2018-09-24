void userenlist(char *name)
{
    FILE *f;
    f = fopen("userlist.txt", "a");
    fputs(name, f);
    fputc(32, f);
    fclose(f);
}

char* disp_users(char users[100][100])
{
    FILE *f;
    f = fopen("userlist.txt", "rb");
    int i = 0, j = 0, flag = 1;
    while ( flag == 1 )
    {
        //printf("%d. ", i);
        char ch;
        while ( !feof(f) )
        {
            char ch = fgetc(f);
            if ( ch == ' ' )
            {
                users[i][j] = '\0';
                i++;
                j = 0;
                break;
            }
            else
            {
                users[i][j] = ch;
                j++;
            }
        }
        //printf("\n");
        if (feof(f))
        {
            flag = 0;
            break;
        }
        //i++;
    }
    return *users;
    fclose(f);
}
