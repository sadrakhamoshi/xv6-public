#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[])
{
    int child_pid, wait_time, run_time;
    int wait_time2, run_time2;
    int pid = fork();
    if (pid < 0)
    {
        printf(1, "fork failed ...!\n");
        exit();
    }
    if (pid == 0)
    {
        pid = fork();
        if (pid < 0)
        {
            printf(1, "fork failed ...!\n");
            exit();
        }
        if (pid == 0)
        {
            sleep(600);
        }
        else
        {
            int child_oldPriority = set_priority(10);
            sleep(600);

            child_pid = waitx(&wait_time2, &run_time2);
            child_oldPriority = set_priority(20);
            printf(1, "\n child wait time : %d , Parent RunTime : %d with cild pid : %d and child_oldPriority : %d\n", wait_time2, run_time2, child_pid, child_oldPriority);
        }
    }
    else
    {
        int parent_oldPriority = set_priority(80);
        sleep(600);

        child_pid = waitx(&wait_time, &run_time);
        parent_oldPriority = set_priority(40);
        printf(1, "\n Parent wait time : %d , Parent RunTime : %d with cildpid : %d and parent_oldPriority : %d\n", wait_time, run_time, child_pid, parent_oldPriority);
    }
    exit();
}
