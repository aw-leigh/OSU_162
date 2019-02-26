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
    if(head != nullptr)
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
}

//Accessors
QueueNode * Queue::getFront()
{
    if(head == nullptr)  //no nodes
    {
        std::cout << "The queue is empty! 1 \n";
    }
    else
    {
        return this->head;
    }    
}
bool Queue::isEmpty()
{
    return this->head == nullptr;
}
void Queue::printQueue()  //prints the names of characters in the queue
{
    if(head == nullptr)  //no nodes
    {
        std::cout << "The queue is empty! 2 \n";
    }
    else
    {
        QueueNode * tempNodePtr = head->prev;
        do
        {
            std::cout << tempNodePtr->name << "\n";
            tempNodePtr = tempNodePtr->prev;
        }while(tempNodePtr != head->prev);
    } 
}

//Modifiers
void Queue::addBack(Character * fighter, std::string name)
{
    if(head == nullptr)  //if the queue is empty
    {
        head = new QueueNode(fighter, name);
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
        tempNodePtr->next = new QueueNode(fighter, name, tempNodePtr, head);
        head->prev = tempNodePtr->next;
    }
}
void Queue::removeFront()
{
    if(head == nullptr)  //no nodes
    {
        std::cout << "The queue is empty! 3 \n";
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
void Queue::removeFrontandDelete()
{
    if(head == nullptr)  //no nodes
    {
        std::cout << "The queue is empty! 3 \n";
    }
    else if (head->next == head)  //only one node
    {
        delete head->fighter;
        delete head;
        head = nullptr;
    }
    else  //2+ nodes remaining
    {
        QueueNode * tempNodePtr = head->prev;
        tempNodePtr->next = head->next;
        tempNodePtr = head->next;
        tempNodePtr->prev = head->prev;
        delete head->fighter;
        delete head;
        head = tempNodePtr;
    }
}