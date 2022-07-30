#include <func.h>
//
// 此程序意在证明子进程把父进程在data段，堆以及栈上的数据都复制了一份
//
int globalVal = 10; // 全局变量，位于data段

int main()
{
    int val = 1; // 栈上的数据
    int* pheap = (int *)malloc(sizeof(int)); // 堆上的数据
    *pheap = 100;

    pid_t pid = fork();
    ERROR_CHECK(pid, -1, "fork");

    if(pid == 0){
        globalVal++;
        val++;
        (*pheap)++;
    }else{
        // 父进程休眠两秒再打印值
        sleep(2);
    }

    printf("globalVal = %d, val = %d, *pheap = %d\n", globalVal, val, *pheap);

    return 0;
}
