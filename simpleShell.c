#include "shellHeader.h"

/**
* main - New version of shell!
* @argc: Shell numb of args.
* @argv: The actual args.
**/

int main(void) {
  int error = 1, chars = 1, e = 1;
  pid_t pid;
  size_t size = 20;
  char *command;
  char *exec;
  char *buffer;
  char **argv;

  command = (char *) malloc(sizeof(char) * size);
  if (command == NULL)
  {
  strPrint("Memory error!\n");
  return(0);
  }

  while (e != 0) /** Main loop **/
  {
    strPrint("AttoufShell$ "); /** Shell init **/

    chars = getline(&command, &size, stdin); /** Command handle **/
    if (chars == -1)
    return (0);
    command = strtok(command, "\n");
    argv = strSplit(command, " ");
    exec = getPath(argv[0]);
    pid = fork(); /** Initializing new process and executing program **/
    wait(NULL);
    if (pid == 0)
    {
      error = execve(exec, argv, NULL);
      if (error < 0)
      {
      buffer = strCat(argv[0], ": No such file or directory\n");
      strPrint(buffer);
      free(buffer);
      }
    }
    free(exec);
    free(command);
    freeArr(argv);
  }

}
