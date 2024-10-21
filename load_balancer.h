#ifndef LOADBALANCER_H
#define LOADBALANCER_H

#include "request_queue.h"
#include "web_server.h"
#include <vector>


/**
 * @brief Manages load balancing of web requests across multiple servers.
 */
class LoadBalancer {
    private:
        int num_servers; /**< The current number of servers. */
        int active_servers; /**< The current number of active servers. */
        int curr_clock_cycle; /**< The current clock cycle of the simulation. */
        RequestQueue queue; /**< The queue holding the incoming web requests. */
        std::vector<WebServer> servers; /**< A list of web servers used to process requests. */

        /**
         * @brief Allocates an additional server to handle increased load.
         */
        void allocate_server();

        /**
         * @brief Deallocates a server to reduce resource usage when the load decreases.
         */
        void deallocate_server();

    public:
        /**
         * @brief Constructs a LoadBalancer with a specified number of servers.
         * @param num_servers The initial number of servers to start with.
         */
        LoadBalancer(int num_servers);

        /**
         * @brief Adds a new request to the load balancer's queue.
         * @param req The web request to be added.
         */
        void add_request(Request req);

        /**
         * @brief Increments the current clock cycle of the simulation.
         */
        void increment_clock_cycle();

        /**
         * @brief Adjusts the number of servers dynamically based on the current load.
         */
        void adjust_server_count();

        /**
         * @brief Distributes requests from the queue to available servers.
         */
        void distribute_requests();

        /**
         * @brief Gets the current clock cycle of the simulation.
         * @return The current clock cycle as an integer.
         */
        int get_clock_cyle();

        /**
         * @brief Gets the number of remaining requests in the request queue.
         * @return The number of remaining requests as an integer.
         */
        int get_remaining_requests();

        /**
         * @brief Gets the number of active webservers.
         * @return The number active servers as an integer.
         */
        int get_active_servers();
};



#endif