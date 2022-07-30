#include <func.h>

int main()
{
    int fd[2];
    int retVal = pipe(fd);
    ERROR_CHECK(retVal, -1, "pipe");

    char buf[1024] = {0};
    write(fd[1], "Hello from pipe", 15); // fd[1]是管道的写端
    read(fd[0], buf, 1024); // fd[0]是管道的读端

    printf("%s\n", buf);

    return 0;
}
