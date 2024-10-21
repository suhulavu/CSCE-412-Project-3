#ifndef WEBSERVER_H
#define WEBSERVER_H

#include "request.h"

/**
 * @brief Represents a web server that processes web requests.
 */
class WebServer {
    private:
        int id; /**< The unique identifier for the web server. */
    public:
        /**
         * @brief Constructs a WebServer with the given ID.
         * @param id The unique identifier for the web server.
         */
        WebServer(int id);

        /**
         * @brief Processes a given web request.
         * @param req The request to be processed.
         * @note This function simulates the processing of a request.
         */
        void process_request(Request req);
};



#endif