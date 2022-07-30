#include <func.h>

int main()
{
    int fd= open("1.pipe", O_RDONLY);
    ERROR_CHECK(fd, -1, "open");

    puts("pipe open!");
    char buf[1024] = {0};

    read(fd, buf, 1024);
    printf("from pipe: %s", buf);

    return 0;
}
