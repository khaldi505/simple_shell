#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
int main(void) {
const char *name = "PATH";
char *value = "atef";
char *token;
int overwrite = 1, i = 0;
extern char **environ;

  while (environ[i]) {
      printf("%s\n", environ[i]);
  i++;
}
printf("\n\n\n\n=============================\n\n\n\n\n");
i = 0;
while (environ[i]) {
  token = strtok(environ[i], "=");
  printf("%s\n", token);
  if (strcmp(token, name) == 0) {
    token = strtok(NULL, " ");
    token = "atef";
    printf("%s\n", token);
    break;
  }
  i++;
}
printf("\n\n\n\n=============================\n\n\n\n\n");

i = 0;
  while (environ[i]) {
      printf("%s\n", environ[i]);
  i++;
}
}
