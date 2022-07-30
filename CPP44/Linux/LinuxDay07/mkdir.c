#include <func.h>

int main(int argc, char *argv[]){
    // ./mkdir dir
    ARGS_CHECK(argc, 2);

    int retVal = mkdir(argv[1], 0777);
    
    ERROR_CHECK(retVal, -1, "mkdir");
    return 0;
}
