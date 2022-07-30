#include <func.h>

int main(int argc, char *argv[])
{
    // ./chat 1.pipe 2.pipe
    ARGS_CHECK(argc, 3);

    int fd1 = open(argv[1], O_RDONLY);
    ERROR_CHECK(fd1, -1, "open");

    //puts("pipe 1 open!");

    int fd2 = open(argv[2], O_WRONLY);
    ERROR_CHECK(fd2, -1, "open");

    //puts("pipe 2 open!");
    
    char buf[1024] = {0};

    // 先打印管道1中对方发来的消息，再通过管道2发送消息给对方
    while(1){
        // 这里有一个顺序问题，由于必须先读管道再读stdin，因此容易阻塞
        memset(buf, 0, sizeof(buf)); // 清空缓存
        read(fd1, buf, sizeof(buf)); // 把管道1的内容读到buf里
        printf("from qiang: %s\n", buf); // 打印buf里的内容

        memset(buf, 0, sizeof(buf)); // 清空缓存
        read(STDIN_FILENO, buf, sizeof(buf)); // 把stdin的内容读到buf里
        write(fd2, buf, strlen(buf)); // 将buf里的内容写到管道2中     
    }

    return 0;
}
