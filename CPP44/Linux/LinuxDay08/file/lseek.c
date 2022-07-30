#include <func.h>

int main(int argc, char* argv[])
{
    // ./lseek file offset
    ARGS_CHECK(argc, 3);

    int fd = open(argv[1], O_RDONLY);
    ERROR_CHECK(fd, -1, "open");
    
    long offset = atoi(argv[2]);
    int retVal = lseek(fd, offset, SEEK_CUR);
    ERROR_CHECK(retVal, -1, "lseek");

    char buf[20] = {0};
    read(fd, buf, 20);
    puts(buf);

    return 0;
} 
