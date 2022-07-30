#include <func.h>
//
// 父进程通过wait函数为子进程“收尸”
//
void print_wstatus(int wstatus);

int main()
{
    pid_t pid;
    int wstatus = 0;
    
    pid = fork();
    ERROR_CHECK(pid, -1, "fork");

    if(pid == 0){
        // 子进程执行的代码
        exit(123);
    }
    // 父进程执行的代码
    int retVal = waitpid(pid, &wstatus, WNOHANG);
    ERROR_CHECK(retVal, -1, "waitpid");
    if(retVal > 0){
        printf("%d was dead.\n", pid);
        print_wstatus(wstatus); // 打印子进程退出时的状态
    }

    pid = fork();
    ERROR_CHECK(pid, -1, "fork");

    if(pid == 0){
        abort();
    }
    retVal = waitpid(pid, &wstatus, 0);
    ERROR_CHECK(retVal, -1, "waitpid");
    printf("%d was dead.\n", pid);
    print_wstatus(wstatus);

    pid = fork();
    ERROR_CHECK(pid, -1, "fork");

    if(pid == 0){
        int a = 10 / 0;
        printf("a = %d\n", a); // 除0异常引发中断
    }
    retVal = waitpid(pid, &wstatus, 0);
    printf("%d was dead.\n", pid);
    print_wstatus(wstatus);

    return 0;
}

void print_wstatus(int wstatus){
    if(WIFEXITED(wstatus)){ // 非0说明子进程正常结束
        // 返回子进程退出时的值
        printf("exit code is %d.\n", WEXITSTATUS(wstatus)); 
    }else if(WIFSIGNALED(wstatus)) { // 非0说明子进程收到信号异常结束
        // 返回使子进程终止的信号
        printf("termination signal is %d.\n", WTERMSIG(wstatus));
#ifdef WCOREDUMP // 非0说明子进程生成了core dump
        printf("(code dump) \n");
#else
        printf("\n");
#endif
    }
}
