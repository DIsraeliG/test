#include <func.h>

int main()
{
    int fd[2];
    // 先pipe
    int retVal = pipe(fd);
    ERROR_CHECK(retVal, -1, "pipe");

    // 再fork
    pid_t pid = fork();
    ERROR_CHECK(pid, -1, "fork");

    // 父亲写，孩子读
    if(pid == 0){
        // 孩子关闭写端
        close(fd[1]);
        char buf[1024] = {0};
        read(fd[0], buf, 1024);

        printf("child: %s\n", buf);
        exit(0);
    }
    // 父亲关闭读端
    close(fd[0]);
    write(fd[1], "Hello from parent", 17);

    exit(0);
}
