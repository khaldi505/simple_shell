#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char const *argv[]) {
  int i = 0;
  while(argv[i])
  {
    printf("%s\n", argv[i]);
    i++;
  }
  return 0;
}
