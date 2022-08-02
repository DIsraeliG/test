#include <func.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int test0()
{
    // ARGS_CHECK(argc, 3);
    // 创建监听套接字
    int sfd = socket(AF_INET, SOCK_STREAM, 0);
    ERROR_CHECK(sfd, -1, "socket");

    struct sockaddr_in serAddr;
    memset(&serAddr, 0, sizeof(serAddr));
    serAddr.sin_family = AF_INET;
    serAddr.sin_port = htons(8888);
    serAddr.sin_addr.s_addr = inet_addr("192.168.146.140");

    // 绑定网络地址
    int ret = bind(sfd, (struct sockaddr*)&serAddr, sizeof(serAddr));
    ERROR_CHECK(ret, -1, "bind");
    // 进行监听
    ret = listen(sfd, 100);
    ERROR_CHECK(ret, -1, "listen");
    printf("listen has completed.\n");

    // // 和客户端的tcp连接
    // socklen_t len;
    // len = sizeof(struct sockaddr);
    // int newFd = accept(sfd, NULL, &len); // accept返回取下的连接的文件描述符，用于和客户端交互
    // ERROR_CHECK(newFd, -1, "accept");
    // ret = send(newFd, "helloclient", 11, 0);
    // ERROR_CHECK(ret, -1, "send");
    // char buf[64] = {0};
    // ret = recv(newFd, buf, sizeof(buf), 0);
    // printf("buf=%s\n", buf);
    // close(newFd);

    while(1);

    close(sfd);

}

int main(int argc, char* argv[])
{
    test0();
    
    return 0;
}