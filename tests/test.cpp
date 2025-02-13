#include <gtest/gtest.h>
#include "../include/TcpServer.h"


class TcpServerTestFixture : public::testing::Test{
public:

    TcpServer* server;
    void SetUp(){
        // add setup code
        server = new TcpServer(8001);
    };

    void TearDown(){
        delete server;
    };
};


// A simple test case
TEST_F(TcpServerTestFixture, Test_Port_Number) {
    EXPECT_EQ(server->port_num, 8001);
};