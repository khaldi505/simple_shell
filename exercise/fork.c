#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
int main(void) {
  pid_t id;
  int i;
  id = fork();
  for (i = 0; i < 10; i++)
  {
  if (id == 0)
  printf("Hello ena lwlad\n");
  else
  {
  wait(NULL);
  printf("Ena l bobaye\n");
  }
  printf("-----------------\n");
  }
}
