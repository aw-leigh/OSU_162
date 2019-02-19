/***************************************************************
** Program name: queue.hpp 
** Author:       Andrew Wilson 
** Date:         February 19, 2019
** Description:  This is the Queue class implementation file.
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

#include <iostream>
#include "queue.hpp"

//Constructors & Deconstructor
Queue::Queue()
{
    this->head = nullptr;
}
Queue::~Queue()
{
    //delete everything
    QueueNode * tempNodePtr = head->prev;
    while(tempNodePtr != head)
    {
        QueueNode * garbage = tempNodePtr;
        tempNodePtr = tempNodePtr->prev;
        delete garbage;
    }
    delete head;
}

//Accessors
int Queue::getFront()
{
    if(head == nullptr)  //no nodes
    {
        std::cout << "The queue is empty! \n";
        return -1;
    }
    else
    {
        return this->head->val;
    }    
}
bool Queue::isEmpty()
{
    return this->head == nullptr;
}
void Queue::printQueue()
{
    if(head == nullptr)  //no nodes
    {
        std::cout << "The queue is empty! \n";
    }
    else
    {
        QueueNode * tempNodePtr = head;
        do
        {
            std::cout << tempNodePtr->val << " ";
            tempNodePtr = tempNodePtr->next;
        }while(tempNodePtr != head);
    } 
}

//Modifiers
void Queue::addBack(int val)
{
    if(head == nullptr)  //if the queue is empty
    {
        head = new QueueNode(val);
        head->next = head;
        head->prev = head;
    }
    else
    {
        //use tempNodePtr to transverse queue until the end
        QueueNode * tempNodePtr = head;
        while(tempNodePtr->next != head)
        {
            tempNodePtr = tempNodePtr->next;
        }
        //create a new node with value, and with tempNodePtr as previous
        tempNodePtr->next = new QueueNode(val, tempNodePtr, head);
        head->prev = tempNodePtr->next;
    }
}
void Queue::removeFront()
{
    if(head == nullptr)  //no nodes
    {
        std::cout << "The queue is empty! \n";
    }
    else if (head->next == head)  //only one node
    {
        delete head;
        head = nullptr;
    }
    else  //2+ nodes remaining
    {
        QueueNode * tempNodePtr = head->prev;
        tempNodePtr->next = head->next;
        tempNodePtr = head->next;
        tempNodePtr->prev = head->prev;
        delete head;
        head = tempNodePtr;
    }
}