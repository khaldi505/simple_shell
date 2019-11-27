#ifndef _SHELLHEADER_
#define _SHELLHEADER_

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

extern char **environ;

int strLen(const char *str);
int strCmp(const char *str1, const char *str2);
char *strCat(const char *str1, const char *str2);
char **strSplit(char *str, const char *delim);
void strPrint(const char *str);
int _putchar(char c);

char *getPath(char *str);
char *pathStr();

void freeArr(char **str);

#endif
