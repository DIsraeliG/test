#include <func.h>

int main(){
    printf("before fork.\n");
    // 创建子进程
    pid_t pid = fork();

    ERROR_CHECK(pid, -1, "fork");
    
    if(pid > 0){
        printf("parent: who is your daddy?\n");
        printf("pid = %d\n", getpid());
    }else{
        printf("child: I'm a baby.\n");
        printf("pid = %d\n", getpid());
    }

    return 0;
}
