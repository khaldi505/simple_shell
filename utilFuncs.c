#include "shellHeader.h"

/** strCat - Concatinates two strings with manual allocation.
  * @str1: first string.
  * @str2: second string.
  * Return: pointer to the newly created string
  **/
char *getPath(char *str)
{
struct stat st;
extern char **environ;
char **paths;
char *token;
char *path;
char *aux;
int i = 0;
int j = 0;

while (environ[i]) {
  token = strtok(environ[i], "=");
  if (strCmp(token, "PATH") == 0) {
    token = strtok(NULL, "\n");
    break;
  }
  i++;
}

paths = strSplit(token, ":");
while (paths[j]) {
  aux = strCat(paths[j], "/");
  path = strCat(aux, str);
  free(aux);
  if (stat(path, &st) == 0) {
    freeArr(paths);
    return(path);
  }
  free(path);
  j++;
}
freeArr(paths);
return(NULL);
}
