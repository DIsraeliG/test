#include <func.h>

int main(int argc, char *argv[])
{
    // ./redirect file
    
    ARGS_CHECK(argc, 2);

    int fd = open(argv[1], O_RDWR);
    ERROR_CHECK(fd, -1, "open");
    
    close(STDOUT_FILENO);

    int retVal = dup2(fd, STDOUT_FILENO);
    ERROR_CHECK(retVal, -1, "dup2");

    puts("Hello from stdout!\n");

    return 0;
}
