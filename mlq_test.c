#include "types.h"
#include "stat.h"
#include "user.h"

void CreateProcess(int process_count, int idx)
{
    if (idx == process_count)
        for (;;)
            ; //busy wait
    int pid = fork();

    // child
    if (pid == 0)
        CreateProcess(process_count, idx + 1);

    // parent
    else if (pid > 0)
    {
        sleep(1000);
        printf(0, "Running process ---> index : %d and pid : %d\n", idx, pid);
        int tmp = 0;
        for (int i = 0; i < 100000; i++)
            tmp = (i % 12 + tmp ) % 31; //some computation for the process
    }
    else
        printf(0, "E: fork error");
}

int main(void)
{
    int pid = fork();

    if (pid < 0)
    {
        printf(0, "Erorr: fork error in main");
    }
    else if (pid > 0)
    {
        wait();
    }
    else
    {
        CreateProcess(8, 0);
    }
    exit();
}
