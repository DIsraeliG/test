#include <func.h>

int main()
{
    pid_t pid = fork();
    ERROR_CHECK(pid, -1, "fork");

    if(pid == 0){
        sleep(2);
        printf("child: group id = %d, session id = %d\n", getpgid(0), getsid(0));
        setsid();
        printf("child: group id = %d, session id = %d\n", getpgid(0), getsid(0));
        exit(0);
    }

    printf("parent: pid = %d, pgid = %d, sid = %d\n", getpid(), getpgid(0), getsid(0));
    waitpid(pid, NULL, 0);

    return 0;
}
