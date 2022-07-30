#include <func.h>

int main(int argc, char *argv[])
{
    // ./chat 1.pipe 2.pipe
    ARGS_CHECK(argc, 3);

    int fd1 = open(argv[1], O_WRONLY);
    ERROR_CHECK(fd1, -1, "open");

    //puts("pipe 1 open!");

    int fd2 = open(argv[2], O_RDONLY);
    ERROR_CHECK(fd2, -1, "open");

    //puts("pipe 2 open!");
    
    char buf[1024] = {0};

    // 先通过管道1发送消息给对方，再打印管道2中对方发来的消息
    while(1){
        memset(buf, 0, sizeof(buf)); // 清空缓存
        read(STDIN_FILENO, buf, sizeof(buf)); // 把stdin的内容读到buf里
        write(fd1, buf, strlen(buf)); // 将buf里的内容写到管道1中    

        memset(buf, 0, sizeof(buf)); // 清空缓存
        read(fd2, buf, sizeof(buf)); // 把管道2的内容读到buf里 
        printf("from mei: %s\n", buf); // 打印buf里的内容
    }

    return 0;
}
