#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "SocketServer.h"


#include <iostream>
#include <arpa/inet.h> 
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;



Class MockSocketSever : public ISocket{
    public:
    MOCK_METHOD(int, socketCreate, (), (override));
    MOCK_METHOD(int, socketBind, (int), (override));
    MOCK_METHOD(int, socketListen, (int), (override));
    MOCK_METHOD(int, serverAccept, (int, sockaddr_in), (override));
    MOCK_METHOD(int, serverSend, (int, const char*), (override));
    MOCK_METHOD(int, serverReceive, (int, char*), (override));
    
}






/*

class TcpServerTestFixture : public::testing::Test{
public:
    TcpServer* server = nullptr;

    void SetUp(){
        // add setup code
        //server = new TcpServer(8000);
    };

    void TearDown(){
        //delete server;
    };
};


TEST_F(TcpServerTestFixture, Test_Port_Number) {

    int sock = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8000);
    if (inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        exit(EXIT_FAILURE);
    }

    int connection = connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr));

    if(connection < 0){
        cout << "Error on connection" << endl;
    }
    cout << "Connection is " << connection << endl;



    const char* message = "GET /users/data v0.3";
    ssize_t bytesSent = send(sock, message, strlen(message), 0);
    if(bytesSent < 0){
        perror("Error on send");
    }
    std::cout << "Sent " << bytesSent << " bytes: " << message << std::endl;


    char buffer[1024] = {0};
    ssize_t bytes_received = recv(sock, buffer, sizeof(buffer) - 1, 0); // Leave space for '\0'

    if (bytes_received > 0) {
        buffer[bytes_received] = '\0';  // Manually add null-terminator
    } else if (bytes_received == 0) {
        std::cout << "Connection closed by peer." << std::endl;
    } else {
        perror("recv failed");
    }
    
    std::cout << "Recieved " << bytes_received<< " bytes: " << buffer << std::endl;



    close(sock);

    ASSERT_TRUE(connection > -1);
};

*/