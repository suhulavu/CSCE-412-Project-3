#include "web_server.h"
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

WebServer::WebServer(int id) {
    this->id = id;
}

void WebServer::process_request(Request req) {
    cout << "Server " << id << " started processing request: "
    << req.ip_in << " -> " << req.ip_out << "; (Processing Time: "
    << req.time << " ms, Job Type: " << req.job_type << ")" << endl;

    // sleep for request time
    this_thread::sleep_for(chrono::milliseconds(req.time));

    cout << "Server " << id << " finished processing request: "
    << req.ip_in << " -> " << req.ip_out << "; (Processing Time: "
    << req.time << " ms, Job Type: " << req.job_type << ")" << endl;
}