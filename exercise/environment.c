#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
int main(int ac, char *av[]) {
int i;
extern char **environ;
while (environ[i]) {
  printf("%s\n", environ[i]);
  i++;
}
return 0;
}
