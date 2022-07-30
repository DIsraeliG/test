#include <func.h>

int mysystem(char *cmd);

int main(int argc, char* argv[])
{
    ARGS_CHECK(argc, 2);

    mysystem(argv[1]);

    return 0;
}

int mysystem(char *cmd){
    // 创建一个子进程来完成mysystem
    pid_t pid = fork();
    ERROR_CHECK(pid, -1, "fork");

    if(pid == 0){
        // -c表示下一个参数就是bash要执行的命令
        execlp("bash", "bash", "-c", cmd, NULL);
        // 这里不想清空用户态缓冲区，因此不用exit()
        _exit(127);
    }else{
        waitpid(pid, 0, 0);
    }

    return 0;
}
