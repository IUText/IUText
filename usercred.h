/* usercred.h: To create usercred.txt file storing username and password */

void usercred(char *username, char *password)
{
    FILE *f;
    f = fopen("usercred.txt", "a");
    fputs(username, f);
    fputc(32, f);
    fputs(password, f);
    fputc(32, f);
    fputc(10, f);
    fclose(f);
}
