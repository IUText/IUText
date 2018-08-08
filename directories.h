/* directories.h: to create user folders */

void directories(char *name)
{
    char command[1000] = "mkdir ";
    strcat(command, name);
    system(command);
}
