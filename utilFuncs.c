#include "shellHeader.h"

/**
* getPath - gets path of file.
* @str: the file.
* Return: pointer to file location.
**/
char *getPath(char *str)
{
struct stat st;
char *token, *path, *aux, **paths;
int j = 0;

token = pathStr();
paths = strSplit(token, ":");
while (paths[j])
{
aux = strCat(paths[j], "/");
path = strCat(aux, str);
free(aux);
if (stat(path, &st) == 0)
{
freeArr(paths);
return (path);
}
free(path);
j++;
}
freeArr(paths);
return (NULL);
}


/**
* pathStr - gets PATHS env variable.
* Return: pointer to PATHS.
**/
char *pathStr()
{
char *token;
int i = 0;

while (environ[i])
{
token = strtok(environ[i], "=");
if (strCmp(token, "PATH") == 0)
{
token = strtok(NULL, "\0");
printf("%s\n", token);
break;
}
i++;
}
return (token);
}
