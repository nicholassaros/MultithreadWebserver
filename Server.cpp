#include <iostream>

#include "TcpServer.h"

using namespace std;


int main(){
    TcpServer server(8000);
    server.SocketListen();
}
