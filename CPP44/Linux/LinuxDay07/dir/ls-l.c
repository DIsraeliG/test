#include <func.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    // ./opendir dir
    ARGS_CHECK(argc, 2);
    DIR *pdir = opendir(argv[1]);
    ERROR_CHECK(pdir, NULL, "opendir");
    
    chdir(argv[1]); // 改变当前工作目录
    // 读写目录项
    struct dirent* pdirent;
    while((pdirent = readdir(pdir)) != NULL){
        struct stat statbuf;
        int retVal = stat(pdirent->d_name, &statbuf);
        ERROR_CHECK(retVal, -1, "stat");

        printf("%6o %ld %s %s %ld %s %s\n", statbuf.st_mode, statbuf.st_nlink, getpwuid(statbuf.st_uid)->pw_name, getgrgid(statbuf.st_gid)->gr_name, statbuf.st_size, ctime(&statbuf.st_mtime), pdirent->d_name);
    }

    closedir(pdir);
    
    return 0;
}
