#include "shellHeader.h"

/**
* main - New version of shell!
* @argc: number of arguments.
* @argv: the arguments.
* @env: the environment.
* Return: void.
**/

int main(__attribute__((unused)) int argc, char **argv, char **env)
{
pid_t pid;
size_t size = 32;
char *command, *buffer;
char **argum;
while (1)
{
command = (char *) malloc(sizeof(char) * size);
if (command == NULL)
{
strPrint("Memory error!\n");
exit(0);
}
if (isatty(STDIN_FILENO) == 1)
strPrint("#cisfun$ "); /** Shell init **/
if ((getline(&command, &size, stdin)) == -1) /** Command handle **/
{
free(command);
exit(0);
}
argum = strSplit(command, " \n");
free(command);
pid = fork(); /** Initializing new process and executing program **/
wait(NULL);
if (pid == 0 && (argum[0] != NULL))
{
if ((execve(argum[0], argum, env)) < 0)
{
buffer = strCat(argv[0], ": No such file or directory\n");
strPrint(buffer);
free(buffer);
}
}
freeArr(argum);
}
freeArr(argum);
exit(1);
}
