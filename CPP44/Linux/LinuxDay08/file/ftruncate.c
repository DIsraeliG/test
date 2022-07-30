#include<func.h>

int main(int argc, char *argv[]){
    // ./ftruncate file length
    
    ARGS_CHECK(argc, 3);
    // 可读可写的模式打开file
    int fd = open(argv[1], O_RDWR);
    ERROR_CHECK(fd, -1, "open");
    // 这里的长度是一个字符串，因此需要用atoi转换成整数
    int length = atoi(argv[2]);
    int retVal = ftruncate(fd, length);
    ERROR_CHECK(retVal, -1, "ftruncate");

    return 0;
}

