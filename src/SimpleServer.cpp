#include "SimpleServer.h"
#include "SocketServer.h"
#include "HttpsObjects.h"


#include <iostream>
#include <fstream>
#include <sstream>


using namespace std;


SimpleServer::SimpleServer(ISocket& _server)
    : server(_server){}


int SimpleServer::SetupServer(){

    serverSock = server.socketCreate();
    if(serverSock < 0){
        perror("Server socket creation failed!");
        return 1;
    }

    if(server.socketBind(serverSock) < 0){
        perror("Server binding to the socket failed!");
        return 1;
    }
    printf("Server bound to socket on port %d \n", server.PORT);
    return 0;
}

int SimpleServer::StartServer(){

    if(server.socketListen(serverSock) < 0){
        perror("Listen Failed, Server not listening!");
        return 1;
    }

    printf("Server listening over port %d...\n", server.PORT);


    while(true){
        // loop to handle connections
        cout << "Waiting for incoming connections... \n";

        sockaddr_in clientAddr{};
        int clientSock = server.socketAccept(serverSock, clientAddr);
        if(clientSock < 0 ){
            perror("Server failed to accept client connection!");
            continue;
        }

        cout << "Connection accepted! Processing request... \n";
        ProcessClient(clientSock);
        cout << "Finished processing request! \n";            
    }
    return 0;
};


void SimpleServer::ProcessClient(int clientSock){
// calls helper functions to process the clients request

        // calls handleRequest
        HTTPS_REQUEST request = HandleRequest(clientSock);

        // calls handleResponse
        HTTPS_RESPONSE response;
        HandleResponse(request, response);

        // takes response and parses into buffer
        string serializedData = SerializeResponse(response);
        if(server.socketSend(clientSock, serializedData.c_str()) < 0){
            perror("Failed to send response");
        }
};


HTTPS_REQUEST SimpleServer::HandleRequest(int clientSock){
    char buffer[1024] = {0};

    if(server.socketReceive(clientSock, buffer) < 0){
        perror("Error Receiving data from client!");
    }

    // HTTPS_REQUEST constructor will parse out raw buffer
    return HTTPS_REQUEST(buffer);
};


void SimpleServer::HandleResponse(HTTPS_REQUEST& request, HTTPS_RESPONSE& response){
    // parses request object and returns a response object

    if(request.path != ""){
        response.content = ReadFile("../RETURN_ME.JSON");
    }

    response.status = "OK";
    response.status_code = 200;
};


string SimpleServer::ReadFile(const string& fileName){
    ifstream file(fileName);

    if(!file){
        perror("Error opening file!");
        return "";
    }

    stringstream buffer;
    buffer << file.rdbuf();

    return buffer.str();
};


string SimpleServer::SerializeResponse(HTTPS_RESPONSE& response){
    stringstream buffer;

    buffer << response.content << "\n"
        << response.content_length << "\n"
        << response.content_type << "\n"
        << response.method << "\n"
        << response.status << "\n"
        << response.status_code;

    return buffer.str();
};
  

