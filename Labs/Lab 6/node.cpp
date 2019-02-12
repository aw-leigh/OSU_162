/***************************************************************
** Program name: node.hpp 
** Author:       Andrew Wilson 
** Date:         February 12, 2019
** Description:  This is the Node class specification file.
**               A node has three member variables:
**               next, a pointer to the next Node object
**               prev, a pointer to the previous Node object
**               val, integer value the specific Node contains
***************************************************************/

#include "node.hpp"

//Constructors & Deconstructor
Node::Node()
{
    this->val = 1337;
    this->next = nullptr;
    this->prev = nullptr;
}
Node::Node(int val, Node * prev, Node * next)
{
    this->val = val;
    this->next = next;
    this->prev = prev;
}
Node::~Node()
{

}

//Accessors
Node * Node::getNext() const
{
    return this->next;
}
Node * Node::getPrev() const
{
    return this->prev;
}
int Node::getVal() const
{
    return this->val;
}

//Modifiers
void Node::setNext(Node * next)
{
    this->next = next;
}
void Node::setPrev(Node * prev)
{
    this->prev = prev;
}
void Node::setVal(int val)
{
    this->val = val;
}