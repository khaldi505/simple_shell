#include "shellHeader.h"

/**
* main - New version of shell!
* Return: void.
**/

int main(__attribute__((unused)) int argc, char **argv)
{
int error = 1, chars = 1;
pid_t pid;
size_t size = 20;
char *command, *buffer;
command = (char *) malloc(sizeof(char) * size);
if (command == NULL)
{
strPrint("Memory error!\n");
return (0);
}
while(1)
{
strPrint("#cisfun$ "); /** Shell init **/
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
buffer = strCat(argv[0], ": No such file or directory\n");
strPrint(buffer);
free(buffer);
}
}
free(command);
}
}
