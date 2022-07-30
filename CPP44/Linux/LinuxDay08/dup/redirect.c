#include <func.h>

int main(int argc, char* argv[])
{
    // ./redirect file
    
    ARGS_CHECK(argc, 2);

    close(STDOUT_FILENO); // 把1（stdout流）关闭了，1成了最小的可用的文件描述符
    int fd = open(argv[1], O_RDWR);
    ERROR_CHECK(fd, -1, "open");

    puts("Hello from he.\n");

    return 0;

}
