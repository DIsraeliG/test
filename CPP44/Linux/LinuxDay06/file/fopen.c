#include <func.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    // ./fopen file 第一个参数是函数名，第二个参数是文件
    ARGS_CHECK(argc, 2);
    
    FILE* fp = fopen(argv[1], "a+");

    ERROR_CHECK(fp, NULL, "fopen");

    // 读写 file1
    fputs("I love xixi.\n", fp);
    fputs("I love xixi.\n", fp);
    fputs("I love xixi.\n", fp);
    
    rewind(fp);
    fputs("How are you.\n", fp);

    char buf[1024] = {0};
    fgets(buf, 1024, fp);

    puts(buf);

    return 0;
}
