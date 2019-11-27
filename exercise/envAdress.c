#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
int main(int ac, char *av[], char *env[]) {
int i;
extern char **environ;
printf("%p\n", &environ);
printf("%p\n", &env);
return 0;
}
