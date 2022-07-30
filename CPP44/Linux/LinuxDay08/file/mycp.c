#include<func.h>

int main(int argc, char *argv[]){
    // ./mycp src dest
    ARGS_CHECK(argc, 3);
    // src 只读即可
    int fdr = open(argv[1], O_RDONLY);
    ERROR_CHECK(fdr, -1, "open fdr");
    // dest需要写权限，此外cp会自动覆盖原文件所以需要O_TRUNC来实现这个清空功能
    int fdw = open(argv[2], O_WRONLY | O_TRUNC | O_CREAT, 0666);
    ERROR_CHECK(fdw, -1, "open fdw");
    
    char buf[4096];
    int len;

    while(1){
        // 把src的内容读到buf里
        len = read(fdr, buf, 4096);
        ERROR_CHECK(len, -1, "read"); // 是否读取成功
        if(len == 0){
            break;
        }
        // 把buf里的数据写到dest里，读多少写多少
        int retVal = write(fdw, b(retVal, -1, "write"); // 是否写成功
    }

    return 0;
}

