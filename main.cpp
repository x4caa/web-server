#include <winsock.h>
#include <iostream>
#include "SockAddr_In.h"
int main() {
    SockAddr_In addr;
    addr.port = 8080;
    addr.ipAddr = inet_addr("127.0.0.1");

    SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    bind(sock, (SOCKADDR*)&addr, sizeof(addr));
    listen(sock, SOMAXCONN);

    std::cout << "Server is listening on port " << ntohs(addr.networkPort) << std::endl;
    std::cout << "IP Address: " << inet_ntoa(*(in_addr*)&addr.networkIpAddr) << ":" << ntohs(addr.networkPort) << std::endl;

    while (true) {
        SOCKET clientSock = accept(sock, nullptr, nullptr);
        if (clientSock != INVALID_SOCKET) {
            std::cout << "Client connected!" << std::endl;
            closesocket(clientSock);
        }
    }

    system("pause");
    return 0;
}