#ifndef REQUESTQUEUE_H
#define REQUESTQUEUE_H

#include "request.h"
#include <queue>


/**
 * @brief Manages a queue of web requests.
 */
class RequestQueue {
    private:
        std::queue<Request> queue; /**< The underlying queue used to store requests. */

    public:
        /**
         * @brief Constructs an empty RequestQueue.
         */
        RequestQueue();

        /**
         * @brief Adds a request to the queue.
         * @param req The request to be added.
         */
        void push(Request req);

        /**
         * @brief Removes and returns the next request from the queue.
         * @return The request that was at the front of the queue.
         * @note This function should be called only if the queue is not empty.
         */
        Request pop();

        /**
         * @brief Gets the number of requests currently in the queue.
         * @return The number of requests in the queue.
         */
        int size();

        /**
         * @brief Checks if the queue is empty.
         * @return True if the queue is empty, false otherwise.
         */
        bool empty();
};


#endif