#include "load_balancer.h"
#include <iostream>

LoadBalancer::LoadBalancer(int num_servers) : num_servers(num_servers), curr_clock_cycle(0) {
    for (int i = 0; i < num_servers; i++) {
        WebServer server = WebServer(i + 1);
        servers.push_back(server);
    }
}

void LoadBalancer::allocate_server() {
    WebServer new_server = WebServer(num_servers + 1);
    servers.push_back(new_server);
    num_servers++;
    cout << "Allocated Server. Total # of Servers: " << num_servers << endl;
}

void LoadBalancer::deallocate_server() {
    // need a minimum of one server
    if (num_servers >= 2) {
        servers.pop_back();
        num_servers--;
        cout << "Deallocated Server. Total # of Servers: " << num_servers << endl;
    }
}

void LoadBalancer::add_request(Request req) {
    queue.push(req);
}

void LoadBalancer::increment_clock_cycle() {
    curr_clock_cycle++;
}

void LoadBalancer::adjust_server_count() {
    if (queue.size() < num_servers) {
        deallocate_server();
    }

    if (queue.size() > num_servers * 5) {
        allocate_server();
    }
}

void LoadBalancer::distribute_requests() {
    if (!queue.empty()) {
        for (int i = 0; i < num_servers; i++) {
            if (!queue.empty()) {
                Request req = queue.pop();
                servers.at(i).process_request(req);
            }
        }
    }
}