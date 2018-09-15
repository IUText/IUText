void userenlist(char *name)
{
    FILE *f;
    f = fopen("userlist.txt", "a");
    fputs(name, f);
    fputc(32, f);
    fclose(f);
}

void disp_users()
{
    FILE *f;
    f = fopen("userlist.txt", "rb");
    int i = 1, flag = 1;
    while ( flag == 1 )
    {
        printf("%d. ", i);
        char ch;
        while ( !feof(f) )
        {
            char ch = fgetc(f);
            if ( ch == ' ' )
                break;
            else
                printf("%c", ch);
        }
        printf("\n");
        if (feof(f))
        {
            flag = 0;
            break;
        }
        i++;
    }
    fclose(f);
}
