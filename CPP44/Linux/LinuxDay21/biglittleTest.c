#include<stdio.h>
#include<stdlib.h>
#include<head.h>

int main(int argc, char *argv[]){
    // *p:1
    int a = 1;
    char *p = &a;
    printf("*p:%d\n", *p);
    
    // *p2:78
    int b = 0x12345678;
    printf("b:%x\n", b);
    char *p2 = &b;
    printf("*p2:%x\n", *p2);

    return 0;
}
