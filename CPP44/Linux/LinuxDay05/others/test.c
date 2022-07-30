#include <stdio.h>

int main(){
#ifdef N
    printf("N defined.\n");
#else
    printf("N not defined.\n");
#endif

    return 0;
}
