#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<pthread.h>
#include <head.h>

void test0(){
    int listenfd = socket(AF_INET, SOCK_STREAM, 0);
    ERROR_CHECK(listenfd, -1, "socket");

    struct sockaddr_in serveraddr;

    int ret = bind(listenfd, &serveraddr, sizeof(serveraddr));
}

int main(int argc, char *argv[])
{
    test0();

    return 0;
}
