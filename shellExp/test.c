#include "shellHeader.h"

int main(void) {
  char **paths;
  char *path = pathStr();
  char *program;
  char *ls = strCat("l","b");
  int i = 0;
  paths = strSplit(path, ":");

  while (paths[i]) {
    printf("%s\n", paths[i]);
    i++;
  }
  program = getPath(ls);

  printf("size of paths = %lu\n", sizeof(paths));
  printf("Program = %s\n", program);
  free(ls);
  free(program);
  free(path);
  freeArr(paths);
  return 0;
}
