#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[])
{
    int pid;
    int child_pid, wait_time, run_time;
    int wait_time2, run_time2;
    int s1, s2;
    pid = fork();
    if (pid < 0)
    {
        printf(1, "fork faild!\n");
        exit();
    }
    if (pid == 0)
    {
        pid = fork();
        if (pid < 0)
        {
            printf(1, "fork faild!\n");
            exit();
        }
        if (pid == 0)
        {
            for (int i = 0; i < 100000; i++)
            {
                i *= 5 + i / 20;
            }
        }
        else
        {
            s1 = set_priority(90);
            for (int i = 0; i < 100000; i++)
            {
                i *= 5 + i / 20;
            }
            child_pid = waitx(&wait_time2, &run_time2);
	    s1 = set_priority(20);
            printf(1, "\n child wait time : %d , Parent RunTime : %d with cildpid : %d and s1 : %d\n", wait_time2, run_time2, child_pid, s1);
        }
    }
    else
    {
        s2 = set_priority(30);
        for (int i = 0; i < 100000; i++)
        {
            i *= 5 + i / 20;
        }
        child_pid = waitx(&wait_time, &run_time);
        s2 = set_priority(10);
        printf(1, "\n Parent wait time : %d , Parent RunTime : %d with cildpid : %d and s2 : %d\n", wait_time, run_time, child_pid, s2);
    }
    exit();
}
