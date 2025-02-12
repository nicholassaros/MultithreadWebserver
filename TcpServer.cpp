#include <iostream>

#include "TcpServer.h"
#include "httpsRequest.h"

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


    // loop to keep server alive and handel incoming connections
    while(1){
        int incomingSocket = accept(serverSocket, NULL, NULL); // accept incoming socket connection on our serverSocket 
        if(incomingSocket < 0){
            // throw error 
            continue; // keep looping, only one connection failed
        }
        const char* response = handleRequest(incomingSocket).c_str();
        ssize_t bytes_sent = send(incomingSocket, response, strlen(response), 0);

        if (bytes_sent < 0){
            // throw error
        }
        closeRequest(incomingSocket);
    }
}

string TcpServer::handleRequest(int incomingSocket){
    char buffer[1024] = {0};
    ssize_t bytes_received = recv(incomingSocket, buffer, sizeof(buffer) - 1, 0);

    if(bytes_received < 0){
        // return error
    } else {
        buffer[bytes_received] = '\n';
    }

    HTTPS_Request request = HTTPS_Request(buffer);

    if(request.method == "GET"){
        return "GET METHOD DETECTED";
    }
}




