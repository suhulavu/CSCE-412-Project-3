#include <iostream>
#include <ctime>
#include <thread>
#include <string>

#include "load_balancer.h"
#include "request.h"

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
    return req;
}



int main() {
    // seed rng
    srand(time(NULL));

    // get user inputs
    int num_servers, num_clock_cycles;
    cout << "Enter total number of web servers: ";
    cin >> num_servers;
    cout << "Enter number of clock cycles: ";
    cin >> num_clock_cycles;

    // fill load balancer with requests
    LoadBalancer load_balancer(num_servers);
    const int INITIAL_REQUESTS = num_servers * 100;
    for (int i = 0; i < INITIAL_REQUESTS; i++) {
        load_balancer.add_request(generate_request());
    }

    // run simulation
    while (load_balancer.get_clock_cyle() <= num_clock_cycles) {
        cout << "Current Clock Cycle: " << load_balancer.get_clock_cyle() << endl;
        // process requests on current clock cycle
        load_balancer.distribute_requests();

        // 20% chance to add request to queue
        if (rand() % 100 < 20) {
            Request new_req = generate_request();
            cout << "New request added to request queue." << endl;
            load_balancer.add_request(new_req);
        }

        // dynamically adjust servers
        // load_balancer.adjust_server_count();

        // increment clock cycle
        load_balancer.increment_clock_cycle();
    }

    return 0;
}