void encrypt(char *text)
{
    printf("Encrypting.\n");
    int i;
    for ( i = 0 ; text[i] !=  NULL ; i++ )
    {
        text[i] -= 2;
    }
}
