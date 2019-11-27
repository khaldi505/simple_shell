#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
int main(void) {
  pid_t id, idc;
  int i = 0;
  char *argv[] = {"/bin/ls", "-l", NULL};
  char *env[] = {"PWD=/home/xfreak/atef", NULL};
  printf("Parent ID: %d\n", getpid());
  id = fork();
  wait(NULL);
  id = fork();
  wait(NULL);
  id = fork();
  wait(NULL);
  if (id == 0)
  {
  printf("\n\n-------------------------------------\n\n");
  execve(argv[0], argv, env);
  }
}
