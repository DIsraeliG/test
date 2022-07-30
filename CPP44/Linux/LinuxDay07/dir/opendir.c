#include <func.h>
#include <stdio.h>

int main(int argc, char *argv[]){
    // ./opendir dir
    ARGS_CHECK(argc, 2);
    DIR *pdir = opendir(argv[1]);
    ERROR_CHECK(pdir, NULL, "opendir");

    // 读写目录项
    struct dirent* pdirent = readdir(pdir);
    printf("%d %s\n", pdirent->d_type, pdirent->d_name);

    closedir(pdir);
    
    return 0;
}
