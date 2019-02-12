/***************************************************************
** Program name: linkedlist.hpp 
** Author:       Andrew Wilson 
** Date:         February 12, 2019
** Description:  This is the LinkedList class implementation file.
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

#include "linkedlist.hpp"

//Constructors & Deconstructor
Linkedlist::Linkedlist()
{
    this->head = nullptr;
    this->tail = nullptr;
}
Linkedlist::~Linkedlist()
{
    Node * tempPointer = head;
    while(tempPointer != nullptr)
    {
        Node * garbage = tempPointer;
        tempPointer = tempPointer->getNext();
        delete garbage;
    }    
}

void Linkedlist::addNodeHead(int val)
{
    //if this is the first node added, it is both head and tail
    if(this->head == nullptr && this->tail == nullptr)
    {
        Node * newNode = new Node(val);
        this->head = newNode;
        this->tail = newNode;
    }
    else
    {
        Node * newNode = new Node(val);
        head->setPrev(newNode);  //old node prev is new node
        newNode->setNext(head);  //new node next is old node
        head = newNode;          //head is new node
    }
}
void Linkedlist::addNodeTail(int val)
{
    //if this is the first node added, it is both head and tail
    if(this->head == nullptr && this->tail == nullptr)
    {
        Node * newNode = new Node(val);
        this->head = newNode;
        this->tail = newNode;
    }
    else
    {
        Node * newNode = new Node(val);
        tail->setNext(newNode);  //old node next is new node
        newNode->setPrev(tail);  //new node prev is old node
        tail = newNode;          //tail is new node
    }   
}
void Linkedlist::rmNodeHead()  //crashes when it deletes last one
{
    if(head == nullptr)  //if there are no nodes
    {
        std::cout << "There are no nodes to delete!" << std::endl;
        systemPause();
    }
    else if(head->getNext() == nullptr)  //if there is only one node
    {
        delete head;
        this->head = nullptr;
        this->tail = nullptr;
    }
    else  //if there are 2+ nodes
    {
        head = head->getNext();
        delete head->getPrev();
        head->setPrev(nullptr);
    }
}
void Linkedlist::rmNodeTail()  //crashes when it deletes last one
{
    if(tail == nullptr)  //if there are no nodes
    {
        std::cout << "There are no nodes to delete!" << std::endl;
        systemPause();
    }
    else if(tail->getPrev() == nullptr)  //if there is only one node
    {
        delete head;
        this->head = nullptr;
        this->tail = nullptr;
    }
    else  //if there are 2+ nodes
    {    
        tail = tail->getPrev();
        delete tail->getNext();
        tail->setNext(nullptr);
    }
}
void Linkedlist::transverseForward()
{
    clearScreen();
    if(this->head == nullptr && this->tail == nullptr)  //if list is empty
    {
        std::cout << "Your list is empty!" << std::endl;
    }
    else
    {
        std::cout << "Your linked list is: ";
        Node * tempPointer = head;
        while(tempPointer != nullptr)
        {
            std::cout << tempPointer->getVal() << " ";
            tempPointer = tempPointer->getNext();
        }
        std::cout << std::endl;
    }
}
void Linkedlist::transverseBackward()
{
    clearScreen();
    if(this->head == nullptr && this->tail == nullptr)  //if list is empty
    {
        std::cout << "Your list is empty!" << std::endl;
    }
    else
    {
        transverseForward();
        std::cout << "Your reversed linked list is: ";
        Node * tempPointer = tail;
        while(tempPointer != nullptr)
        {
            std::cout << tempPointer->getVal() << " ";
            tempPointer = tempPointer->getPrev();
        }
        std::cout << std::endl;
    }
}
void Linkedlist::getHeadValue()
{
    if(this->head == nullptr && this->tail == nullptr)  //if list is empty
    {
        std::cout << "Your list is empty!" << std::endl;
        systemPause();        
    }
    else
    {
        std::cout << "The value of the head node is: " << head->getVal();
        std::cout << std::endl;
        systemPause();
    }  
}
void Linkedlist::getTailValue()
{
    if(this->head == nullptr && this->tail == nullptr)  //if list is empty
    {
        std::cout << "Your list is empty!" << std::endl;
        systemPause();        
    }
    else
    {
        std::cout << "The value of the tail node is: " << tail->getVal();
        std::cout << std::endl;
        systemPause();
    }
}
void Linkedlist::readFromFile()
{
    int val = 0;
    std::string valTemp = "";

    std::ifstream inputFile;
    inputFile.open("numberfile.txt");
    while(inputFile.good())  //read through to end of file
    {
        getline(inputFile, valTemp, '\n');
        val = stoi(valTemp);
        addNodeHead(val);
    }
    inputFile.close();
}