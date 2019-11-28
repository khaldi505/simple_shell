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
if (stat(path, &st) == 0)
{
free(aux);
freeArr(paths);
free(token);
return (path);
}
free(aux);
free(path);
j++;
}
free(token);
freeArr(paths);
return (NULL);
}


/**
* pathStr - gets PATHS env variable.
* Return: pointer to PATHS.
**/
char *pathStr()
{
char *token, *result;
char **aux;
int i = 0;

aux = arrCopy(environ);
while (aux[i])
{
token = strtok(aux[i], "=");
if (strCmp(token, "PATH") == 0)
{
token = strtok(NULL, "\0");
break;
}
i++;
}
result = strCat(token, "");
freeArr(aux);
return (result);
}

/**
* pathStr - gets PATHS env variable.
* Return: pointer to PATHS.
**/
char **arrCopy(char **src)
{
char **dest;
int i = 0, len = 0;

while (src[len])
len++;

dest = malloc(sizeof(char *) * len);
if (dest == NULL)
{
strPrint("Memory error");
exit(0);
}

while (src[i])
{
dest[i] = strCat(src[i], "");
i++;
}
return(dest);
}
