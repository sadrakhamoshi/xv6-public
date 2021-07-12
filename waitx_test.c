#include "types.h"
#include "stat.h"
#include "user.h"
int main(int argc, char *argv[])
{
    int wtime = 0, rtime = 0;
    int pid = fork();
    if (pid < 0)
    {
        printf(0, "Error in fork \n");
        exit();
    }
    if (pid == 0)
    {
        printf(0, "sleep child\n");
        sleep(500);
        printf(0, "after sleep child\n");
    }
    else if (pid > 0)
    {
        printf(0, "wait in parent\n");
        waitx(&wtime, &rtime);
        printf(0, "parent wait time=%d, parent run time=%d\n", wtime, rtime);
    }
    exit();
}
