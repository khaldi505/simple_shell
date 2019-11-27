#include "shellHeader.h"

/**
* main - New version of shell!
* @argc: Shell numb of args.
* @argv: The actual args.
**/

int main(void) {
  int e = 1, error = 1;
  pid_t pid;
  char *command, *token;
  char **argv;
  int chars = 1;
  size_t size = 20;
  command = (char *) malloc(sizeof(char) * size);
  if (command == NULL)
  printf("Memory error!\n");
  while (e != 0)
  {
    printf("AttoufShell$ ");
    chars = getline(&command, &size, stdin);
    if (chars == -1)
    return (0);
    argv = argGen(command);
    token = strtok(command, "\n");
    token = findPath(token);

    pid = fork();
    wait(NULL);
    if (pid == 0)
    {
      error = execve(token, argv, NULL);
      if (error < 0)
      printf("%s: No such file or directory\n", argv[0]);
    }
    free(argv);
  }
}
