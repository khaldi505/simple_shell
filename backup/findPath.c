#include "shellHeader.h"

/**
  * findPath - Finds the path of a program.
  * @prog: The program.
  * Return: return a string of full path of program.
**/

char *findPath(char *prog)
{
char **paths;
char *path, *verif;
char *newprog = addSlash(prog);
int plen = 0, palen = 0;
const struct stat st;
struct stat status;
int i = 0;
paths = getPath();
while (paths[i])
{
status = st;
verif = strCat(paths[i], newprog);
if (stat(verif, &status) == 0) {
  return(verif);
}
i++;
}
free(newprog);
return (NULL);
}


char **getPath() {
int i = 0;
char *path;
char **paths;
extern char **environ;
while (environ[i]) {
  path = strtok(environ[i], "=");
  if (strcmp(path, "PATH") == 0) {
    path = strtok(NULL, "\0");
    break;
  }
  i++;
}
paths = pathGen(path);
return (paths);
}


/**
* _strcat - concatinates two strings
* @dest: The destination string
* @src: source string.
* Return: src.
*/
char *addSlash(char *prog)
{
int i = 0, j = 0;
char *newprog;
while (prog[i])
i++;
i++;
newprog = malloc(sizeof(char) * i);
if (newprog == NULL)
return (NULL);
newprog[0] = '/';
for (j = 0; j < i; j++)
newprog[j + 1] = prog[j];
return (newprog);
}

char * strCat(const char *str1, const char *str2)
{
    size_t s1, s2, s3, i = 0;
    char *a;

    s1 = strlen(str1);
    s2 = strlen(str2);
    s3 = s1+s2+1;
    a = malloc(s3);

    while(*str1 != '\0') {
        a[i] = *str1;
        str1++;
        i++;
    }
    while(*str2 != '\0') {
        a[i] = *str2;
        str2++;
        i++;
    }

    a[i] = '\0';                    // Here i = s1 + s2

    return a;
}
