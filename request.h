#ifndef REQUEST_H
#define REQUEST_H

#include <string>

using namespace std;

/**
 * @brief Represents a web request in the load balancer system.
 */
struct Request {
    string ip_in;    /**< The incoming IP address of the request. */
    string ip_out;   /**< The outgoing IP address for the response. */
    int time;             /**< Processing time for the request in clock cycles. */
    char job_type;        /**< Type of the job: 'P' for processing, 'S' for streaming. */
};

#endif