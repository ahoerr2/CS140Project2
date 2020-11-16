//A C++ implementation of a linked list node. The node has a string payload and a reference to the next avaliable node.
//All elements of the class are avaliable to be modified by the Ordered Linked List

#pragma once

#include <string>

// Forward declaration of OrderedList
class OrderedList;

class Node
{
    //Allows the linked list to access protected and private members of the class
    friend class OrderedList;
public:
    explicit Node(const std::string& p);
private:
    std::string payload;
    Node* nextNode{ nullptr };
};