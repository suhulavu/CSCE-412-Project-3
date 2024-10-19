#ifndef WEBSERVER_H
#define WEBSERVER_H

#include "request.h"


class WebServer {
    private:
        int id;
    public:
        WebServer(int id);
        void process_request(Request req);
};



#endif