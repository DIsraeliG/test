#include <func.h>

int main()
{
    pid_t pid = fork();
    ERROR_CHECK(pid, -1, "fork");

    if(pid == 0){
        setpgid(0, 0); // 子进程自己当组长，自立为王
        // setpgid(getpid(), getpid());
        printf("child: pgid = %d\n", getpgid(0)); // 0表示获取自己的pid
    } else {
        sleep(2);
        setpgid(pid, getpgid(0));
        printf("parent: child pgid = %d\n", getpgid(pid));
        printf("parent: pid = %d\n", getpid());
        printf("parent: pgid = %d\n", getpgid(0));
    }

    return 0;
}
