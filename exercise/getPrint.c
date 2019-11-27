#include <atef.h>
int main(void) {
  size_t size = 5;
  size_t chars;
  char *buffer;
  buffer = (char *) malloc(sizeof(char) * size);
  if (buffer == NULL) {
    printf("Error\n");
    return 0;
  }
  printf("Type something: \n");
  chars = getline(&buffer, &size, stdin);
  printf("%s\n", buffer);
  return 0;
}
