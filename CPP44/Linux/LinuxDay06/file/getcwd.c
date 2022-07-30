#include <func.h>

int main()
{
    // char buf[10]
    char *cwd = getcwd(NULL, 0);

    ERROR_CHECK(cwd, NULL, "getcwd");

    printf("cwd = %s\n", cwd);

    free(cwd);

    return 0;
}
