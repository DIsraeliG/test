#include <stdio.h>

void foo(int i){
    foo(i++);
}
int main(){
    foo(1);

    return 0;
}
