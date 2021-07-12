#include "types.h"
#include "stat.h"
#include "user.h"

//                     ind 0  1  2  3  4  5  6  7  8  9  10
int test_queue_lvl[100] = {1, 2, 3, 1, 1, 2, 3, 1, 1, 2, 3};

//A  procedure used to create the test processes.
void create_test_processes(int pcnt, int idx)
{
  while (pcnt != idx)
  {
    int pid = fork();
    if (pid == 0)
    {
      idx++;
    }
    else if (pid > 0)
    {
      sleep(1000);
      printf(0, "Running process with index=%d and pid=%d\n", idx, pid);
      int tmp = 47;
      for (int i = 0; i < 10000000; i++)
      {
        tmp = (tmp + i % 13) % 23;
      }
    }
    else
    {
      printf(0, "E: fork error");
    }
  }
  while (1 == 1)
  {
  }
}

int main(void)
{

  int pid = fork();

  if (pid < 0)
  {
    printf(0, "E: fork error in main");
  }
  else if (pid > 0)
  {
    wait();
  }
  else
  {
    create_test_processes(10, 0);
  }
  exit();
}
