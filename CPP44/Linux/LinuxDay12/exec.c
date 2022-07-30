#include <func.h>

char* init_env[] = {"USER=scrooge", "PATH=/tmp", NULL};

int main()
{
    pid_t pid = fork();
    ERROR_CHECK(pid, -1, "fork");

    if(pid == 0){
        int retval = execle("./echoall", "echoall", "myarg1", "MYARG2", NULL, init_env);
        ERROR_CHECK(retval, -1, "execle");
        printf("Can you see me?");
    }

    waitpid(pid, NULL, 0);

    pid = fork();
    ERROR_CHECK(pid, -1, "fork");

    if(pid == 0){
        int retval = execlp("echoall", "echoall", "only 1 arg", NULL);
        ERROR_CHECK(retval, -1, "execlp");
        printf("You cannot see me!");
    }
    
    waitpid(pid, NULL, 0);

    return 0;
}
