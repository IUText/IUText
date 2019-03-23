void userlist(char *name)
{
    FILE *f;
    f = fopen("userlist.txt", "a");
    fputs(name, f);
    fputc(32, f);
    fclose(f);
}
