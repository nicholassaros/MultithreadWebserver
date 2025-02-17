#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../src/SimpleServer.cpp"
#include "../include/SocketServer.h"

#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>


using namespace std;



class MockSocketServer : public ISocket {
    public:
        MOCK_METHOD(int, socketCreate, (), (override));
        MOCK_METHOD(int, socketBind, (int), (override));
        MOCK_METHOD(int, socketListen, (int), (override));
        MOCK_METHOD(int, socketAccept, (int, sockaddr_in), (override));  // Pass by reference
        MOCK_METHOD(int, socketSend, (int, const char*), (override));
        MOCK_METHOD(int, socketReceive, (int, char*), (override));  // Pass by reference if needed
    };

TEST(MockSocketServer, TestSetupServer) {
    MockSocketServer mock;
    SimpleServer server(mock);

    int mock_port = 1;

    EXPECT_CALL(mock, socketCreate()).WillOnce(::testing::Return(1));
    EXPECT_CALL(mock, socketBind(mock_port)).WillOnce(::testing::Return(1));


    EXPECT_EQ(server.SetupServer(), 0);
}