#include <func.h>
//
// 此程序意在证明用户态的文件缓冲区也会被子进程复制
//
int main()
{
    // 此时\n把stdout里的内容刷新，因此子进程的stdout里没有hello
    //printf("Hello \n"); // printf是向stdout输数据，这是一个用户态的文件缓冲区
    // 此时stdout没有刷新，内容不变，因此子进程也会打印Hello
    printf("Hello ");

    pid_t pid = fork();
    ERROR_CHECK(pid, -1, "fork");

    if(pid == 0){
        printf("child: world.\n");
    }else{
        printf("parent: world.\n");
    }

}
