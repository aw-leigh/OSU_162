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


#ifndef NODE_HPP
#define NODE_HPP

class Node
{
    private:
        int val;
        Node * next;
        Node * prev;
    public:
        Node();
        Node(int val, Node * prev = nullptr, Node * next = nullptr);
        ~Node();
        Node * getNext() const;
        Node * getPrev() const;
        int getVal() const;
        void setNext(Node * next);
        void setPrev(Node * prev);
        void setVal(int val);
};

#endif //Node