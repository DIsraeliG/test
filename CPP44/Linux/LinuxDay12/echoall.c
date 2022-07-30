#include <func.h>

int main(int argc, char* argv[])
{
    for(int i = 0; i < argc; i++){
        printf("argv[%d]: %s\n", i, argv[i]);
    }

    extern char** environ; // 获取进程的环境变量
    char** ptr; // 准备遍历环境变量
    for(ptr = environ; *ptr != NULL; ptr++){
        printf("%s\n", *ptr);
    } 

    return 0;
}
