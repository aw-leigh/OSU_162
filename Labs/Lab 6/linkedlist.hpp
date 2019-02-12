/***************************************************************
** Program name: linkedlist.hpp 
** Author:       Andrew Wilson 
** Date:         February 12, 2019
** Description:  This is the LinkedList class specification file.
**               A LinkedList has two member variables:
**               head, a pointer to the first Node object
**               tail, a pointer to the last Node object
**               
**               And the following methods:
**               addNodeHead, adds a node to the head
**               addNodeTail, adds a node to the tail
**               rmNodeHead, removes a node from the head
**               rmNodeTail, removes a node from the tail
**               transverseForward, transverses head-to-tail
**               transverseBackward, transverses tail-to-head
***************************************************************/


#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>
#include <fstream>
#include <string>
#include "node.hpp"
#include "validation.hpp"

class Linkedlist
{
    private:
        Node * head;
        Node * tail;
    public:
        Linkedlist();
        ~Linkedlist();
        void addNodeHead(int val);
        void addNodeTail(int val);
        void rmNodeHead();
        void rmNodeTail();
        void transverseForward();
        void transverseBackward();
        void getHeadValue();
        void getTailValue();
        void readFromFile();
};

#endif