#include <func.h>

int main(int argc, char *argv[]){
    // ./chdir path
    ARGS_CHECK(argc, 2);

    int retVal = chdir(argv[1]);

    ERROR_CHECK(retVal, -1, "chdir");

    char* cwd = getcwd(NULL, 0);
    puts(cwd);
    free(cwd);

    return 0;
}

