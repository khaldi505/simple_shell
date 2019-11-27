#include "shellHeader.h"

/**
* main - New version of shell!
* Return: void.
**/

int main(void)
{
int error = 1, chars = 1;
pid_t pid;
size_t size = 20;
char *command, *buffer;
char *argv[] = {"lol", NULL};
command = (char *) malloc(sizeof(char) * size);
if (command == NULL)
{
strPrint("Memory error!\n");
return (0);
}
strPrint("AttoufShell$ "); /** Shell init **/
chars = getline(&command, &size, stdin); /** Command handle **/
if (chars == -1)
return (0);
command = strtok(command, "\n");
pid = fork(); /** Initializing new process and executing program **/
wait(NULL);
if (pid == 0)
{
error = execve(command, argv, NULL);
if (error < 0)
{
buffer = strCat(command, ": No such file or directory\n");
strPrint(buffer);
free(buffer);
}
}
free(command);
}
