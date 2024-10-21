#ifndef REQUEST_H
#define REQUEST_H

#include <string>

using namespace std;

struct Request {
    string ip_in; // incoming ip address
    string ip_out; //outgoing ip address
    int time; // processing time in ms
    char job_type; // p for processing or s for streaming
};

#endif