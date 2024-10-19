#ifndef LOADBALANCER_H
#define LOADBALANCER_H

#include "request_queue.h"
#include "web_server.h"
#include <vector>



class LoadBalancer {
    private:
        int num_servers;
        int curr_clock_cycle;
        RequestQueue queue;
        std::vector<WebServer> servers;
        void allocate_server();
        void deallocate_server();
    public:
        LoadBalancer(int num_servers);
        void add_request(Request req);
        void increment_clock_cycle();
        void adjust_server_count();
        void distribute_requests();
};



#endif