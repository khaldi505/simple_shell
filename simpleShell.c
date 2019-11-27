#include "shellHeader.h"

/**
* main - New version of shell!
* Return: void.
**/

int main(__attribute__((unused)) int argc, char **argv)
{
pid_t pid;
size_t size = 32;
char *command, *buffer, *aux;
char **arguments;
while(1)
{
command = (char *) malloc(sizeof(char) * size);
if (command == NULL)
{
strPrint("Memory error!\n");
return (0);
}
strPrint("#cisfun$ "); /** Shell init **/
if ((getline(&command, &size, stdin)) == -1) /** Command handle **/
{
free(command);
return (0);
}
command = strtok(command, "\n");
aux = strCat(command, "");
arguments = strSplit(command, " ");
printf("%s\n", arguments[0]);
free(command);
pid = fork(); /** Initializing new process and executing program **/
if (wait(NULL) > 0)
{
free(aux);
}
if (pid == 0)
{
if ((execve(arguments[0], arguments, NULL)) < 0)
{
buffer = strCat(argv[0], ": No such file or directory\n");
strPrint(buffer);
free(buffer);
}
}
free(aux);
freeArr(arguments);
}
}
