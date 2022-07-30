#include <func.h>

void foo(){
    printf("I am going to die.\n");
}
int main()
{
    atexit(foo);
    printf("call _exit.");
    _exit(1);
}
