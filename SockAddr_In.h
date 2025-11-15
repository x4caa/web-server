#include <winsock.h>

#ifndef SOCKADDR_IN_H
#define SOCKADDR_IN_H

struct SockAddr_In {
    short addrFamily = AF_INET;
    unsigned short port;
    unsigned short networkPort = htons(port);
    unsigned long ipAddr = INADDR_ANY;
    unsigned long networkIpAddr = htonl(ipAddr);
};

#endif // SOCKADDR_IN_H