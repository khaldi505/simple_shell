#include "shellHeader.h"

/**
  * argGen - generates arguments form a text.
  * @command: The input command.
  * Return: Array of strings = args.
**/

int main(int argc, char **argv) {
extern char **environ;
char *path = argv[1];
char *token;
int i = 0;

while (environ[i]) {
token = strtok(environ[i], "=");
if (strcmp(token, path) == 0) {
token = strtok(NULL, " \n");
printf("%s=%s\n", path,token);
break;
}
i++;
}
}
