#include <func.h>

int main(int argc, char *argv[])
{
    // ./redirect file
    
    ARGS_CHECK(argc, 2);

    int fd = open(argv[1], O_RDWR);
    ERROR_CHECK(fd, -1, "open");
    
    close(STDOUT_FILENO);

    int newfd = dup(fd);
    if(newfd != STDOUT_FILENO){
        fprintf(stderr, "redirect error.\n");
        exit(1);
    }

    puts("Hello from stdout!\n");

    return 0;
}
