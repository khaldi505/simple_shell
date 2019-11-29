#include "shellHeader.h"

int main(void)
{
char *command;
size_t bus = 32;
int ss;
command = (char *)malloc(sizeof(char) * bus);
ss = getline(&command, &bus, stdin);
printf("%s\n", command);
if (isatty(STDIN_FILENO) == 1)
printf("lol\n");

printf("%s\n", command);
}
