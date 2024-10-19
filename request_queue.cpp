#include "request_queue.h"

RequestQueue::RequestQueue() {}

void RequestQueue::push(Request req) {
    queue.push(req);
}

Request RequestQueue::pop() {
    Request req = queue.front();
    queue.pop();
    return req;
}

int RequestQueue::size() {
    return queue.size();
}