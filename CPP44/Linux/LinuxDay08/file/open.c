#include <func.h>

int main(int argc, char *argv[]) {
    // ./open file
    ARGS_CHECK(argc, 2);
    // 打开文件
    int fd = open(argv[1], O_RDWR | O_APPEND); // fd是文件描述符，open的返回值是一个文件描述符
    ERROR_CHECK(fd, -1, "open");

    // 读
    char buf[1024] = {0};
    int len = read(fd, buf, 1024);
    ERROR_CHECK(len, -1, "read");
    
    int retVal = write(fd, buf, len);
    ERROR_CHECK(retVal, -1, "write");

    // puts(buf);
    // 关闭文件
    close(fd);
    return 0;
}
