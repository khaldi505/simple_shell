#include "shellHeader.h"

/**
* strCat - Concatinates two strings with manual allocation.
* @str1: first string.
* @str2: second string.
* Return: pointer to the newly created string
**/
char *strCat(const char *str1, const char *str2)
{
size_t s1, s2, s3, i = 0;
char *a;
s1 = strlen(str1);
s2 = strlen(str2);
s3 = s1 + s2 + 1;
a = malloc(s3);
if (a == NULL)
{
strPrint("Memory error!")
exit(EXIT_FAILURE);
}
while (*str1 != '\0')
{
a[i] = *str1;
str1++;
i++;
}
while (*str2 != '\0')
{
a[i] = *str2;
str2++;
i++;
}
a[i] = '\0';
return (a);
}

/**
* strCmp - Compares two strings.
* @s1: first string.
* @s2: second string.
* Return: 0 if identical.
**/
int strCmp(const char *s1, const char *s2)
{
int j, sr;
sr = 0;
for (j = 0; s1[j] && s2[j]; j++)
{
if (s1[j] != s2[j])
{
sr = s1[j] - s2[j];
break;
}
}
return (sr);
}

/**
* strLen - returns length of string.
* @str: string.
* Return: length of a string.
**/
int strLen(const char *str)
{
int len = 0;
while (str[len])
len++;
return (len);
}

/**
* strSplit - splits a string into an array.
* @str: string.
* @delim: the delimiter.
* Return: array of strings.
**/
char **strSplit(char *str, const char *delim)
{
char *token, *cmd, **arg;
int i = 0, j = 0, k = 0, v = 0, argc = 0;
while (str[j])
{
if (str[j] == delim[0])
{
k = 0;
v = 1;
while (delim[k])
{
if (delim[k] != str[j])
{
v = 0;
break;
}
k++;
j++;
}
if (v == 1)
argc++;
}
j++;
}
argc++;
arg = malloc(sizeof(char *) * (argc + 1));
if (arg == NULL)
return (0);
cmd = strCat(str, "");
token = strtok(cmd, delim);
while (token != NULL)
{
arg[i] = strCat(token, "");
token = strtok(NULL, delim);
i++;
}
arg[i] = NULL;
free(cmd);
return (arg);
}
