#ifndef _SHELLHEADER_
#define _SHELLHEADER_

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

char **argGen(char *command);
char **pathGen(char *command);
char *findPath(char *prog);
char **getPath();
char *addSlash(char *prog);
char *strCat(const char *str1, const char *str2);

#endif
