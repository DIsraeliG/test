#include <func.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <boost/json/src.hpp>

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using namespace boost::json;

int main(int argc, char* argv[])
{
    // 1.创建套接字
    int clientfd = socket(AF_INET, SOCK_STREAM, 0);
    ERROR_CHECK(clientfd, -1, "socket");

    struct sockaddr_in serAddr;
    memset(&serAddr, 0, sizeof(serAddr));
    serAddr.sin_family = AF_INET;
    serAddr.sin_port = htons(8888);
    serAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); 
    // 2. 向服务器发起建立连接的请求
    int ret = connect(clientfd, (struct sockaddr*)&serAddr, sizeof(serAddr));
    ERROR_CHECK(ret, -1, "connect");
    printf("connect has completed.\n");

    // 客户端向服务器发送关键字
    cout << "请输入关键字: \n" <<endl;
    char buf[1000] = {0};
    cin >> buf;
    ret = send(clientfd, buf, strlen(buf), 0);
    ERROR_CHECK(ret, -1, "send");
    memset(buf, 0, sizeof(buf));

    // 客户端接收服务器返回json格式的数据
    object json_data;
    json_data["1"] = "init_string";
    strcpy(buf, serialize(json_data).c_str());
    ret = recv(clientfd, buf, sizeof(buf), 0);
    ERROR_CHECK(ret, -1, "send");
    cout << "recv from server: " << buf << endl;
    memset(buf, 0, sizeof(buf));

    // 客户端选择一个序号发送给服务器
    cout << "输入序号: " << endl;
    cin >> buf;
    ret = send(clientfd, buf, strlen(buf), 0);
    ERROR_CHECK(ret, -1, "send");
    memset(buf, 0, sizeof(buf));

    // 服务器返回客户端选择的序号的相关内容
    strcpy(buf, serialize(json_data).c_str());
    ret = recv(clientfd, buf, sizeof(buf), 0);
    ERROR_CHECK(ret, -1, "send");
    printf("recv from server: %s\n", buf);
    memset(buf, 0, sizeof(buf));

    close(clientfd);

    return 0;
}