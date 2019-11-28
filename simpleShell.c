#include "shellHeader.h"

/**
* main - New version of shell!
* @argc: number of arguments.
* @argv: the arguments
* Return: void.
**/

int main(__attribute__((unused)) int argc, char **argv)
{
pid_t pid;
size_t size = 32;
char *command, *buffer, *aux;
char *arguments[] = {"./hsh", NULL};
while (1)
{
command = (char *) malloc(sizeof(char) * size);
if (command == NULL)
{
strPrint("Memory error!\n");
exit(EXIT_FAILURE);
}
if (isatty(STDIN_FILENO) == 1)
strPrint("#cisfun$ "); /** Shell init **/
if ((getline(&command, &size, stdin)) == -1) /** Command handle **/
{
free(command);
exit(EXIT_FAILURE);
}
command = strtok(command, "\n");
aux = strCat(command, "");
free(command);
pid = fork(); /** Initializing new process and executing program **/
wait(NULL);
if (pid == 0)
{
if ((execve(aux, arguments, NULL)) < 0)
{
buffer = strCat(argv[0], ": No such file or directory\n");
strPrint(buffer);
free(buffer);
}
}
free(aux);
}
exit(EXIT_FAILURE);
}
