#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
char **getPath() {
int i = 0;
char *token;
extern char **environ;
while (environ[i]) {
  token = strtok(environ[i], "=");
  if (strcmp(token, "PATH") == 0) {
    token = strtok(NULL, ":");
    while (token) {
      printf("%s\n",token);
      token = strtok(NULL, ":");
    }
    break;
  }
  i++;
}
}
