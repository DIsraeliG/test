#include <func.h>
#define LENGTH 4096

int main(int argc, char *argv[])
{ 
    // ./mcp src dest
    ARGS_CHECK(argc, 3);
    // 打开src文件
    int fdr = open(argv[1], O_RDONLY);
    ERROR_CHECK(fdr, -1, "open fdr");
    // 打开dest文件
    int fdw = open(argv[2], O_RDWR | O_CREAT | O_TRUNC, 0666);
    ERROR_CHECK(fdw, -1, "open fdw");
    // fstat函数：用文件描述符获得文件状态
    struct stat statbuf;
    fstat(fdr, &statbuf);

    ftruncate(fdw, statbuf.st_size); // 使文件大小不变（迅雷）
    off_t fsize = 0; // offset初始值
    int cp_size; // 每次复制的长度
    
    // 如果offset小于文件大小，说明数据还没有复制完，循环继续
    while(fsize < statbuf.st_size){
        if(statbuf.st_size - fsize >= LENGTH){
            // 如果文件大小-offset大于每次需要复制的字节数（4096），则直接复制4096字节的数据
            cp_size = LENGTH; 
        }else{
            // 如果剩下的文件长度小于4096，则复制剩下的字节（此时剩下的字节数小于4096）
            cp_size = statbuf.st_size - fsize;
        }
        // 将src文件和dest文件映射到内存中
        char* src = (char*)mmap(NULL, cp_size, PROT_READ, MAP_SHARED, fdr, fsize);
        ERROR_CHECK(src, MAP_FAILED, "mmap src");// 注意mmap的返回值不是-1，是MAP_FAILED
        char* dest = (char*)mmap(NULL, cp_size, PROT_WRITE | PROT_READ, MAP_SHARED, fdw, fsize);
        ERROR_CHECK(dest, MAP_FAILED, "mmap dest");

        memcpy(dest, src, cp_size);// 将src指向的内存拷贝到dest指向的内存中
        munmap(src, cp_size); // 解除src现在的内存映射，为下次映射做准备
        munmap(dest, cp_size); // 解除dest现在的内存映射，为下次映射做准备

        fsize += cp_size; // offset更新
    }

    return 0;
}
