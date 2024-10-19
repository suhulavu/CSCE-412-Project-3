#ifndef WEBSERVER_H
#define WEBSERVER_H

#include "request.h"


class WebServer {
    public:
        WebServer();
        void process_request(Request req);
};



#endif