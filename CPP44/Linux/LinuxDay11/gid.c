#include <func.h>

int main()
{
    pid_t pid = getpid();
    pid_t ppid = getppid();

    printf("pid = %d, ppid = %d\n", pid, ppid);
    printf("gid = %d, egid = %d\n", getgid(), getegid());

    return 0;
}
