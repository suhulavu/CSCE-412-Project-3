#include <iostream>
#include <ctime>
#include <thread>
#include <string>

#include "load_balancer.h"
#include "request.h"

using namespace std;


/**
 * @brief Generates a random IP address.
 * @return A string representing a randomly generated IP address.
 */
string generate_ip() {
    int first = rand() % 256;
    int second = rand() % 256;
    int third = rand() % 256;
    int fourth = rand() % 256;

    string ip = to_string(first) + "." + to_string(second) + 
                "." + to_string(third) + "." + to_string(fourth);
    return ip;
}

/**
 * @brief Generates a random web request.
 * @return A Request object with randomly generated IP addresses, processing time, and job type.
 */
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


/**
 * @brief The main function that simulates the load balancer handling web requests.
 * 
 * The program initializes a load balancer with a specified number of servers and simulates
 * the processing of web requests over a given number of clock cycles. The simulation
 * includes generating new requests, distributing them to servers, and adjusting the number
 * of servers dynamically.
 * 
 * @return 0 on successful execution.
 */
int main() {
    // seed rng
    srand(time(NULL));

    // get user inputs
    int num_servers, num_clock_cycles;
    std::cout << "Enter total number of web servers: ";
    cin >> num_servers;
    std::cout << "Enter number of clock cycles: ";
    cin >> num_clock_cycles;

    // fill load balancer with requests
    LoadBalancer load_balancer(num_servers);
    const int INITIAL_REQUESTS = num_servers * 100;
    for (int i = 0; i < INITIAL_REQUESTS; i++) {
        load_balancer.add_request(generate_request());
    }

    // print initial conditions
    std::cout << "Initial Queue Size: " << load_balancer.get_remaining_requests() << " requests." << endl;
    std::cout << "Request completion time is between 1 and 5 milliseconds." << endl;
    std::cout << "Total Number of Servers: " << load_balancer.get_active_servers() << endl;


    // run simulation
    while (load_balancer.get_clock_cyle() <= num_clock_cycles) {
        std::cout << "Current Clock Cycle: " << load_balancer.get_clock_cyle() << endl;
        std::cout << "Current Number of Active Servers: " << load_balancer.get_active_servers() << endl;

        // process requests on current clock cycle
        load_balancer.distribute_requests();

        // 80% chance to add requests to queue
        if (rand() % 100 < 80) {
            int num_reqs = rand() % 20 + 1;
            for (int i = 0; i < num_reqs; i++) {
                Request new_req = generate_request();
                load_balancer.add_request(new_req);
            }
            std::cout << num_reqs << " new request(s) added to request queue." << endl;
        }

        // dynamically adjust servers
        load_balancer.adjust_server_count();

        // increment clock cycle
        load_balancer.increment_clock_cycle();

        // output number of requests remaining
        std::cout << "Number of requests remaining: " << load_balancer.get_remaining_requests() << endl;
    }

    // output
    std::cout << "Final Queue Size: " << load_balancer.get_remaining_requests() << " requests." << endl;
    std::cout << "Final Number of Active Servers: " << load_balancer.get_active_servers() << endl;

    return 0;
}