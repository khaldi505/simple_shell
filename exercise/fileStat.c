#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
int main(int ac, char *av[]) {
int i;
struct stat st;
for (i = 1; i < ac; i++) {
  if (stat(av[i], &st) == 0) {
    printf("FOUND\n");
  }
  else
  printf("NOT FOUND\n");
}
return 0;
}
