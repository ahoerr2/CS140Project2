#pragma once

#include "Node.h"
#include <iostream>
class OrderedList
{
private:
    // 1) A pointer to the first node in the ordered list
    Node* first;


public:
    OrderedList();
    ~OrderedList();

    //Inserts a new node into the list, properly sorted into list, ignores dublicates
    void insert(Node node);
    //Removes a node from a list that matches the payload
    Node remove(const Node& node);
    //Removes the front element of the list, returns a copy of the node
    Node removeFront();
    //Clears all elements in the list
    void clear();
    //Removes all the elements of one lists and inserts them into another list
    void absorb(OrderedList& list);
    //Prints a debug string of the orderedlist
    void printOrderedList();
    //Checks if the list is empty, returns the boolean value true if the list is empty
    bool isEmpty();
};
