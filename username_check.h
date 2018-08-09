/*username_check.h: Checks to see if a given username is already in the userlist.txt file. Returns 0 if it doesn't exist and 1 if it does. */

int username_check(char *username)
{
    int res=0;
    char c[10000];
    FILE *fp;
    fp=fopen("userlist.txt","r");
    fscanf(fp,"%[^\n]", c);
    fclose(fp);
    strcat(c," ");
    strcat(c,username);
    char b[200][200];
    int i, j = 0, k = 0, n, m;
    for (i = 0;c[i] != '\0';i++)
    {
        if (c[i] == ' ')
        {
            b[k][j] = '\0';
            k++;
            j = 0;
        }
        else
        {
            b[k][j] = c[i];
            j++;
        }
    }
    b[k][j] = '\0';
    for (i = 0;i <= k;i++)//kinda bubble sorting stuff
    {
        for (j = i + 1;j <= k;j++)
        {
            if (strcmp(b[i], b[j]) == 0)//if same c is found
            {
                res=1;

            }
        }
    }
    return res;
}

