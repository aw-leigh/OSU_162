/***************************************************************
** Program name: queue.hpp 
** Author:       Andrew Wilson 
** Date:         February 19, 2019
** Description:  This is the Queue class specification file.
**
**               Queue member variables:
**               head, a pointer to the first node in the queue
**
**               Queue member functions:
**               isEmpty, returns true if the queue is empty
**               addBack, takes an int and appends it to the back of the queue
**               getFront, returns the value of the front node
**               removeFront, which deletes the front node
**               printQueue, which prints the queue
***************************************************************/


#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "queuenode.hpp"

class Queue
{
    private:
        QueueNode * head;

    public:
        Queue();
        ~Queue();
        bool isEmpty();
        void addBack(int val);
        int getFront();
        void removeFront();
        void printQueue();
};

#endif //Queue