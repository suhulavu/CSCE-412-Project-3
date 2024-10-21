#include "load_balancer.h"
#include <iostream>

LoadBalancer::LoadBalancer(int num_servers) : num_servers(num_servers), active_servers(num_servers), curr_clock_cycle(1) {
    for (int i = 0; i < num_servers; i++) {
        WebServer server = WebServer(i + 1);
        servers.push_back(server);
    }
}

void LoadBalancer::allocate_server() {
    active_servers++;
    cout << "Allocated Server. Total # of Active Servers: " << active_servers << endl;
}

void LoadBalancer::deallocate_server() {
    // need a minimum of one server
    if (num_servers >= 2) {
        active_servers--;
        cout << "Deallocated Server. Total # of Active Servers: " << active_servers << endl;
    }
}

void LoadBalancer::add_request(Request req) {
    queue.push(req);
}

void LoadBalancer::increment_clock_cycle() {
    curr_clock_cycle++;
}

void LoadBalancer::adjust_server_count() {
    if (queue.size() < active_servers) {
        deallocate_server();
    }

    if (queue.size() > active_servers * 2 && active_servers < num_servers) {
        allocate_server();
    }
}

void LoadBalancer::distribute_requests() {
    if (!queue.empty()) {
        for (int i = 0; i < active_servers; i++) {
            if (!queue.empty()) {
                Request req = queue.pop();
                servers.at(i).process_request(req);
            }
        }
    }
}

int LoadBalancer::get_clock_cyle() {
    return curr_clock_cycle;
}

int LoadBalancer::get_remaining_requests() {
    return queue.size();
}

int LoadBalancer::get_active_servers() {
    return active_servers;
}