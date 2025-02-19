#include "SimpleServer.h"
#include "SocketServer.h"
#include "HttpsObjects.h"


#include <iostream>
#include <fstream>
#include <sstream>
#include <thread>


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

        cout << "Connection accepted! Processing request! Creating new thread... \n";

        //ProcessClient(clientSock);
        thread clientThread(&SimpleServer::ProcessClient, this, clientSock);
        clientThread.detach();
    }

    return 0;
};


int SimpleServer::SendData(int clientSock, const char* data){
    if(server.socketSend(clientSock, data) < 0){
        perror("Failed to send response");
        return 1;
    }
    cout << "Sent response successfully";
    return 0;
}


void SimpleServer::ProcessClient(int clientSock){
// calls helper functions to process the clients request
        sleep(5);

        HTTPS_RESPONSE response;
        HTTPS_REQUEST request = HandleRequest(clientSock);
        HandleResponse(request, response);

        // takes response and parses into buffer
        string serializedData = SerializeResponse(response);
        

        if(SendData(clientSock, serializedData.c_str()) < 0){
            cout << "Finished client request, ERROR!" << endl;
        } else {
            cout << "Finished client request, SUCCESS!" << endl;
        }
}


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

    if(request.method == "GET"){
        response.content = ReadFile(request.path);
        response.content_length = response.content.size();
        response.content_type = "JSON";
        response.status = "OK";
        response.status_code = 200;
        response.method = "GET";
    }
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
  

