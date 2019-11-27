#include "shellHeader.h"

/**
  * argGen - generates arguments form a text.
  * @command: The input command.
  * Return: Array of strings = args.
**/

int main(int argc, char **argv) {
extern char **environ;
char *path = "PATH";
char *file = strCat("/", argv[1]);
char *token, *abpath;
struct stat st;
int i = 0, v;

if (argc != 2) {
printf("Usage: stat filename\n");
return (0);
}

while (environ[i]) {
token = strtok(environ[i], "=");
if (strcmp(token, path) == 0) {
token = strtok(NULL, ":");
break;
}
i++;
}
while (token) {
abpath = strCat(token, file);
v = stat(abpath, &st);
if (v == 0)
printf("%s : FOUND\n", token);
else
free(adpath);
token = strtok(NULL, ":");
}
free(file);
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
