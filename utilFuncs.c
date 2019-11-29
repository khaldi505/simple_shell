#include "shellHeader.h"

/**
* getPath - gets path of file.
* @str: the file.
* Return: pointer to file location.
**/
char *getPath(char *str)
{
struct stat st;
char *token, *tokena, *path, *aux, **paths;
int j = 0, v = 0;
token = pathStr();
tokena = token;
paths = strSplit(token, ":");
free(tokena);
if (stat(str, &st) == 0)
return (str);
while (paths[j])
{
aux = strCat(paths[j], "/");
path = strCat(aux, str);
if (stat(path, &st) == 0)
{
v = 1;
free(aux);
break;
}
free(aux);
free(path);
j++;
}
freeArr(paths);
if (v == 1)
return (path);
return (NULL);
}


/**
* pathStr - gets PATHS env variable.
* Return: pointer to PATHS.
**/
char *pathStr()
{
char *token, *result, *copy, *cp;
char **aux;
int i = 0;

aux = arrCopy(environ);
while (aux[i])
{
copy = strCat(aux[i], "");
cp = copy;
token = strtok(cp, "=");
if (strCmp(token, "PATH") == 0)
{
token = strtok(NULL, "\0");
break;
}
free(copy);
i++;
}
result = strCat(token, "");
free(copy);
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

dest = malloc(sizeof(char *) * (len + 1));
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
dest[i] = NULL;
return(dest);
}

/**
* pathStr - gets PATHS env variable.
* Return: pointer to PATHS.
**/
void checkBuiltin(char *program)
{
char xit[4] = "exit";
if (strCmp(program, xit) == 0)
exit(1);
}
