#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
int main(int ac, char *av[], char *env[]) {
int i = 0;
char *token;
extern char **environ;
while (environ[i]) {
  token = strtok(environ[i], "=");
  if (strcmp(token, av[1]) == 0) {
    printf("%s\n", strtok(NULL, "="));
    break;
  }
  i++;
}
}
