#include <iostream>

#include "TcpServer.h"

#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>


using namespace std;



TcpServer::TcpServer(int port_num){
    serverAddress.sin_family = AF_INET; // specifies IPV4
    serverAddress.sin_port = htons(port_num); // delcare port num and host to network byte order
    serverAddress.sin_addr.s_addr = INADDR_ANY; // listens to all avaliable IP
    
    SocketStart();
};


void TcpServer::SocketStart(){
    serverSocket = socket(AF_INET, SOCK_STREAM,0);

    if(serverSocket < 0){
        // throw error here socket init failed
    }

    if(bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0){
        // throw error here we failed to bind to socket
    }

    // success message for startingSocket
}


void TcpServer::SocketListen(){
    if(listen(serverSocket,MAX_CONNECT) < 0 ){
        // throw error
    }


    // loop to keep server alive and handel income connections
    while(1){
        int incomingSocket = accept(serverSocket, NULL, NULL); // accept incoming socket connection on our serverSocket 
        if(incomingSocket < 0){
            // throw error 
            continue; // keep looping, only one connection failed
        }
        handleRequest(incomingSocket);
        closeRequest(incomingSocket);

    }
}

