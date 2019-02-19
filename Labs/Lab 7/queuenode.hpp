/***************************************************************
** Program name: queuenode.hpp 
** Author:       Andrew Wilson 
** Date:         February 19, 2019
** Description:  This is the QueueNode struct specification file.
**               A Queue contains QueueNode structs, doubly linked nodes that form the queue.
**               A QueueNode stores an int val, and contains pointers prev and next that point to adjacent nodes.
**               Its constructor takes an int which it stores in val, and optionally a pointer to the previous and next nodes
**               If no previous or next nodes are specified, it defaults to nullptr.
***************************************************************/

#ifndef QUEUENODE_HPP
#define QUEUENODE_HPP

struct QueueNode
{
    int val;
    QueueNode * next;
    QueueNode * prev;
    QueueNode(int val, QueueNode * prev = nullptr, QueueNode * next = nullptr)
    {
        this->val = val;
        this->prev = prev;
        this->next = next;
    }
};

#endif //QueueNode