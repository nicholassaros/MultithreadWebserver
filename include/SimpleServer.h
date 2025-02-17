#ifndef SIMPLESERVER_H
#define SIMPLESERVER_H

#include "SocketServer.h"
#include "HttpsObjects.h"


class SimpleServer {
private:
    ISocket& server;
    int serverSock;
    int MAX_CONNECTIONS;

public:
    SimpleServer(ISocket& server);

    int SetupServer();

    int StartServer();

    void ProcessClient(int);

    HTTPS_REQUEST HandleRequest(int);

    void HandleResponse(HTTPS_REQUEST&, HTTPS_RESPONSE&);

    string ReadFile(const string&);

    string SerializeResponse(HTTPS_RESPONSE&);

};


#endif