#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>


int main(void)
{
  pid_t pid;
  int status;
  printf("1. pid = %d\n1. ppid = %d\n", getpid(), getppid());
  pid = fork();
  if (pid == 0)
  {
    printf("2. pid = %d\n2. ppid = %d\n", getpid(), getppid());
    pid = fork();
    if (pid == 0)
    {
      printf("4. pid = %d\n4. ppid = %d\n", getpid(), getppid());
    }
    else
    {
      wait(&status);
    }
  }
  else
  {
    pid = fork();
    if (pid == 0)
    {
      printf("3. pid = %d\n3. ppid = %d\n", getpid(), getppid());
      pid = fork();
      if (pid == 0)
      {
        printf("5. pid = %d\n5. ppid = %d\n", getpid(), getppid());
      }
      else
      {
        pid = fork();
        if (pid == 0)
        {
          printf("6. pid = %d\n6. ppid = %d\n", getpid(), getppid());
        }
        else
        {
          wait(&status);
          wait(&status);
        }
      }
    }
    wait(&status);
    wait(&status);
  }
  exit(0);
}
