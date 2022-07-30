#include <func.h>

int main(int argc, char *argv[]){
    // ./rmdir dir
    
    ARGS_CHECK(argc, 2);
    int retVal = rmdir(argv[1]);
    ERROR_CHECK(retVal, -1, "rmdir");
    return 0;
}

