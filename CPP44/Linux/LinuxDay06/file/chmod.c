#include <func.h>

int main(int argc, int *argv[]){
    // ./chmod 777 file
    ARGS_CHECK(argc, 3);

    mode_t mode;
    sscanf(argv[1], "%o", &mode);

    int retVal = chmod(argv[2], mode);

    ERROR_CHECK(retVal, -1, "chmod");

    return 0;
}
