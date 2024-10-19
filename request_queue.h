#ifndef REQUESTQUEUE_H
#define REQUESTQUEUE_H

#include "request.h"
#include <queue>

class RequestQueue {
    private:
        std::queue<Request> queue;

    public:
        RequestQueue();
        void push(Request req);
        Request pop();
        int size();
};


#endif