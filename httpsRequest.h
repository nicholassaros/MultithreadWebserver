#ifndef HTTPSREQUEST_H
#define HTTPSREQUEST_H

#include <iostream>
#include <sstream>
#include<string>

using namespace std;



struct HTTPS_Request {
    string method;
    string path;
    string version;
    /*
    HTTPS_Request(const string& _method, const string& _path, const string& _version)
        : method(_method), path(_path), version(_version){}

    */

    HTTPS_Request(const char* raw_request) {
        istringstream stream(raw_request);
        string line;

        if(getline(stream, line)){
            istringstream request_line(line);
            request_line >> method >> path >> version;
        }

    }

};


#endif