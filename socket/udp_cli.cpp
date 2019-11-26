#include <iostream>
#include <string>
#include <stdlib.h>
#include "udpsocket.hpp"

#define CHECK_RET(q) if((q)==false){return -1;}
int main(int argc, char *argv[])
{
    if (argc != 3) {
        std::cerr << "./udp_cli ip port\n";
        return -1;
    }
    //这两个地址信息是服务端地址信息，表示数据要由客户端发送给谁
    std::string srv_ip = argv[1];
    uint16_t srv_port = atoi(argv[2]);

    UdpSocket sock;
    CHECK_RET(sock.Socket());
    //客户端通常并不主动绑定地址,而是在发送数据的时候，操作系统检测到还没有绑定
    //则会自动的选择一个合适的地址和端口进行绑定
    while(1) {
        std::cout << "client say:";
        fflush(stdout);
        std::string buf;
        std::cin >> buf;
        sock.Send(buf, srv_ip, srv_port);

        buf.clear();
        sock.Recv(buf);
        std::cout << "server say:"<<buf<<"\n";
    }
    sock.Close();
    std::cout << "Hello world" << std::endl;
    return 0;
}

