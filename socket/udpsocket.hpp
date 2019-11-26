/*
 *封装实现一个UdpSocket类，向外提供简单的结构能够实现udp编程
 *
 */

#include <iostream>
#include <string>
#include <stdio.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>

class UdpSocket {
private:
    int _sockfd;
private:
    //封装一个地址结构
    void MakeAddr(struct sockaddr_in &addr, const std::string &ip, 
                  const uint16_t port){
        addr.sin_family = AF_INET;
        addr.sin_port = htons(port);
        addr.sin_addr.s_addr = inet_addr(ip.c_str());
    }
public:
    UdpSocket():_sockfd(-1) {}
    //1. 创建UDP套接字
    bool Socket() {
        _sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
        if (_sockfd < 0) {
            perror("socket error");
            return false;
        }
        return true;
    }
    //2. 为套接字绑定地址信息
    bool Bind(const std::string &ip, const uint16_t port){
        struct sockaddr_in addr;
        MakeAddr(addr, ip, port);
        socklen_t len = sizeof(struct sockaddr_in);
        int ret = bind(_sockfd, (struct sockaddr*)&addr, len);
        if (ret < 0) {
            perror("bind error");
            return false;
        }
        return true;
    }
    //3. 发送数据
    bool Send(const std::string &buf, std::string &dip, uint16_t dport) {
        struct sockaddr_in addr;
        MakeAddr(addr, dip, dport);
        socklen_t len = sizeof(struct sockaddr_in);

        //ret用于获取实际发送的数据长度，len是指定地址长度
        //sendto(sockfd, data, len, flag, peeraddr, addrlen)
        int ret = sendto(_sockfd, &buf[0], buf.size(), 0, 
                         (struct sockaddr*)&addr, len);
        if (ret < 0) {
            perror("sendto error");
            return false;
        }
        return true;
    }
    //4. 接收数据
    bool Recv(std::string &buf, 
              std::string *ip = NULL, uint16_t *port = NULL) {
        struct sockaddr_in addr;
        socklen_t len = sizeof(struct sockaddr_in);
        char tmp[4096] = {0};
        //recvfrom(sockfd, buf, len, flag, peeraddr, *len);
        //recvfrom不但要获取数据，还要获取对端地址信息，以及实际地址信息长度和实际接收的数据长度
        //ret用于获取实际接收到的数据长度，len用户指定以及获取地址信息长度
        int ret = recvfrom(_sockfd, tmp, 4095, 0, 
                           (struct sockaddr*)&addr, &len);
        if (ret < 0) {
            perror("recvfrom error");
            return false;
        }
        buf.assign(tmp, ret);
        if (ip != NULL) {
            //inet_ntoa将网络字节序整数IP地址转换为字符串IP地址
            *ip = inet_ntoa(addr.sin_addr);
        }
        if (port != NULL) {
            *port = ntohs(addr.sin_port);
        }
        return true;
    }
    //5. 关闭套接字
    bool Close() {
        close(_sockfd);
    }
};


