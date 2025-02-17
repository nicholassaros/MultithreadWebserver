#ifndef HTTPSOBJECTS_H
#define HTTPSOBJECTS_H

#include <iostream>
#include <sstream>


using namespace std;

struct HTTPS_REQUEST {
    string method;
    string path;
    string version;
    /*
    HTTPS_Request(const string& _method, const string& _path, const string& _version)
        : method(_method), path(_path), version(_version){}

    */

    HTTPS_REQUEST(const char* raw_request) {
        istringstream stream(raw_request);
        string line;

        if(getline(stream, line)){
            istringstream request_line(line);
            request_line >> method >> path >> version;
        }
    }
};



struct HTTPS_RESPONSE {
    string method;
    string status;
    int status_code;
    string content_type;
    string content_length;
    string content;
};

#endif