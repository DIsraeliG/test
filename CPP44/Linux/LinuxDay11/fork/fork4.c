#include <func.h>
//
// 此程序意在证明父进程和子进程公用同一个文件对象
//
int main()
{
    int fd = open("file", O_RDWR | O_CREAT | O_TRUNC, 0666);
    ERROR_CHECK(fd, -1, "open");

    write(fd, "Hello", 5);

    pid_t pid = fork();
    if(pid == 0){
        write(fd, "Hello from child\n", 17);
    }else{
        sleep(2);
        write(fd, "Hello from parent\n", 18);
    }

    return 0;
}
