#include <func.h>
// 文件流的底层用到了系统调用
int main(int argc, char* argv[])
{
    ARGS_CHECK(argc, 2);
    
    FILE* fp = fopen(argv[1], "a+");

    //write(3, "Hello!", 6);
    //write(fp->_fileno, "HELLO!", 6);
    write(fileno(fp), "WORLD!", 6);
    printf("\n%d\n", fp->_fileno);

    return 0;
}
