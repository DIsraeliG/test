#include <func.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/epoll.h>


#include <iostream>
#include <string>

int test0()
{
    // ARGS_CHECK(argc, 3);
    // 创建监听套接字
    int listenfd = socket(AF_INET, SOCK_STREAM, 0);
    ERROR_CHECK(listenfd, -1, "socket");

    struct sockaddr_in serAddr;
    memset(&serAddr, 0, sizeof(serAddr));
    serAddr.sin_family = AF_INET;
    // serAddr.sin_addr.s_addr = inet_addr(argv[1]);
    serAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    // serAddr.sin_port = htons(atoi(argv[2]));
    serAddr.sin_port = htons(8888);

    // 绑定网络地址
    int ret = bind(listenfd, (struct sockaddr*)&serAddr, sizeof(serAddr));
    ERROR_CHECK(ret, -1, "bind");
    // 进行监听
    ret = listen(listenfd, 100);
    ERROR_CHECK(ret, -1, "listen");
    printf("listen has completed.\n");

    while(1){
        // // 和客户端的tcp连接
        // socklen_t len;
        // len = sizeof(struct sockaddr);
        // int newFd = accept(listenfd, NULL, &len); // accept返回取下的连接的文件描述符，用于和客户端交互
        int peerfd = accept(listenfd, NULL, NULL);
        ERROR_CHECK(peerfd, -1, "accept");
        printf("accept a client conn.\n");
        char buf[1000] = {0}; // 应用层缓冲区
        ret = recv(peerfd, buf, sizeof(buf), 0);
        ERROR_CHECK(ret, -1, "recv");
        printf("recv message: %s\n", buf);
        memset(buf, 0, sizeof(buf));

        ret = send(peerfd, buf, strlen(buf), 0);
        printf("send message: %s\n", buf);
        memset(buf, 0, sizeof(buf));
    
        close(peerfd);

    }

    close(listenfd);

}

int main(int argc, char* argv[])
{
    test0();
    
    return 0;
}