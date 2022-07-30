#include <func.h>

int main()
{
    int fd1[2];
    int fd2[2];
    pipe(fd1);
    pipe(fd2);

    pid_t pid = fork();
    ERROR_CHECK(pid, -1, "fork");

    char buf[1024] = {0};
    
    // 孩子从fd1写数据，fd2读数据
    // 父亲从fd1读数据，fd2写数据
    if(pid == 0){
        close(fd1[0]);
        close(fd2[1]);
        // child do something
        printf("child: do homework.\n");
        // TELL_PARENT();
        write(fd1[1], "homework done!", 14);
        // WAIT_PARENT();
        read(fd2[0], buf, 1024);
        printf("from parent: %s\n", buf);
        // continue
        printf("child: continue...");
        exit(0);
    }
    
    close(fd1[1]);
    close(fd2[0]);
    // parent do something
    printf("parent: do something...\n");
    // WAIT_CHILD();
    read(fd1[0], buf, 1024);
    // TELL_CHILD();
    write(fd2[1], "Good job!", 9);
    // continue
    printf("parent: continue...");
    exit(0);
}
