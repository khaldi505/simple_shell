#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct atef {
  char *path;
  struct atef *next;
}atef;

int main(int ac, char *av[]) {
int i = 0;
char *token;
atef *lista;
lista = malloc(sizeof(atef));

extern char **environ;
while (environ[i]) {
  token = strtok(environ[i], "=");
  if (strcmp(token, "PATH") == 0) {
    token = strtok(NULL, ":");
    while (token) {
      lista->path = token;
      lista->next = malloc(sizeof(atef));
      printf("%s\n", lista->path);
      lista = lista->next;
      token = strtok(NULL, ":");
    }
    break;
  }
  i++;
}
}
