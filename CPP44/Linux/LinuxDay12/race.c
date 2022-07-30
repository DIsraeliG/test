#include <func.h>

int main()
{
    pid_t pid = fork();
    ERROR_CHECK(pid, -1, "fork");

    if(pid == 0){
        pid = fork();
        ERROR_CHECK(pid, -1, "fork");

        if(pid > 0){
            exit(0); // 第一个孩子死亡
        }
        // 第二个孩子
        // polling(轮询)
        while(getppid() != 1) // 如果第一个孩子没死，就会一直执行这个循环
            ;
        printf("second child, parent pid = %d\n", getppid());
        exit(0);
    }

    waitpid(pid, NULL, 0); // 等待第一个孩子结束

    exit(0);
}
