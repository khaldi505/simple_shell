#include "shellHeader.h"

/**
  * argGen - generates arguments form a text.
  * @command: The input command.
  * Return: Array of strings = args.
**/

char **argGen(char *command)
{
  char *token;
  char **argv;
  int i = 0, j = 0, argc = 0;
  while (command[j]){
  if (command[j] == ' ')
    argc++;
  j++;
  }
  argc++;
  argv = malloc(sizeof(char *) * argc);
  if (argv == NULL)
  return (0);
  token = strtok(command, " ");
  while (token != NULL)
  {
    argv[i] = token;
    printf("%s\n", argv[i]);
    token = strtok(NULL, " ");
    i++;
  }
  argv[i] = NULL;
  return (argv);
}

char **pathGen(char *command)
{
  char *token;
  char **argv;
  int i = 0, j = 0, argc = 0;
  while (command[j]){
  if (command[j] == ':')
    argc++;
  j++;
  }
  argc++;
  argv = malloc(sizeof(char *) * argc + 2);
  if (argv == NULL)
  return (0);
  token = strtok(command, ":");
  while (token != NULL)
  {
    argv[i] = token;
    printf("%s\n", argv[i]);
    token = strtok(NULL, ":");
    i++;
  }
  argv[i] = NULL;
  return (argv);
}
