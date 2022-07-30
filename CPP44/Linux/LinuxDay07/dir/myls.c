#include <func.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    // ./opendir dir
    // 第一部分：判断目录是否成功打开
    ARGS_CHECK(argc, 2);
    DIR *pdir = opendir(argv[1]);
    ERROR_CHECK(pdir, NULL, "opendir");

    // 读写目录项
    struct dirent* pdirent;
    long pos;
    while(1){
        long loc = telldir(pdir);
        pdirent = readdir(pdir);
        if(pdirent == NULL){
            break;
        }
        char *name = pdirent->d_name; // 名字是一个数组，所以数据类型是*name而不是name
        // 如果目录名是 . .. 则不打印名字
        if(strcmp(name, ".") && strcmp(name, "..")){
            printf("%s ", pdirent->d_name);
        }
        // 记录下opendir的位置
        if(strcmp(name, "opendir") == 0){
            pos = loc;
        }
    }    
    printf("\n");
    // 回到opendir所在位置并打印
    seekdir(pdir, pos);
    pdirent = readdir(pdir);
    puts(pdirent->d_name);

    closedir(pdir);
    
    return 0;
}
