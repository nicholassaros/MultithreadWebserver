#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>


class TcpServer {
public:
    sockaddr_in serverAddress;
    int serverSocket;
    const int MAX_CONNECT = 20;

    TcpServer(int port_num);
    ~TcpServer();

    void SocketStart(); // called from constructor

    void SocketListen();

    void handleRequest(int);

    void closeRequest(int);
};

#endif