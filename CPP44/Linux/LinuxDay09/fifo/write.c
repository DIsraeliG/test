#include <func.h>

int main(int argc, char *argv[])
{
    // ./write msg
    
    ARGS_CHECK(argc, 2);

    int fd = open("1.pipe", O_WRONLY);
    ERROR_CHECK(fd, -1, "open");
    puts("pipe open!");

    write(fd, argv[1], strlen(argv[1]));

    return 0;
}
