#include <iostream>
#include <ctime>
#include <thread>
#include <string>

#include "load_balancer.h"

using namespace std;

string generate_ip() {
    int first = rand() % 256;
    int second = rand() % 256;
    int third = rand() % 256;
    int fourth = rand() % 256;

    string ip = to_string(first) + "." + to_string(second) + 
                "." + to_string(third) + "." + to_string(fourth);
    return ip;
}


Request generate_request() {
    Request req;
    req.ip_in = generate_ip();
    req.ip_out = generate_ip();
    req.time = rand() % 10 + 1;
    if (rand() % 2 == 0) {
        req.job_type = 'P';
    }
    else {
        req.job_type = 'S';
    }
}