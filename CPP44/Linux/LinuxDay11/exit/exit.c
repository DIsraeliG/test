#include <func.h>

void foo(){
    printf("I am going to die.");
}
int main()
{
    atexit(foo);
    exit(1);
}
