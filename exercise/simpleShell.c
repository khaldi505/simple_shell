#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
#include <string.h>
int main(int argc, char *argv[]) {
  int e = 1, error = 1;
  pid_t pid;
  char *command, *token;
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
    token = strtok(command, "\n");
    pid = fork();
    wait(NULL);
    if (pid == 0)
    {
      error = execve(token, argv, NULL);
      if (error < 0) {
        printf("%s: No such file or directory\n", argv[0]);
      }
    }
  }
}
