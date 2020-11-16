//Collection created by Gabriel Roy and Alex Hoerr

/*A C++ implementation of the ordered linked list collection. The list takes in nodes that store string payloads, the nodes are sorted
* and do not allow dublicate nodes to be inserted into the list. The collection also has the ability to remove nodes from the list 
* and return their values. The collection can also absorb all the nodes of another linked list collection, and insert them into
* its own list. A debug output printing method is included.
 */

#pragma once

#include "Node.h"
#include <iostream>
class OrderedList
{
private:
    //A pointer to the first node in the ordered list
    Node* first;


public:
    OrderedList();
    ~OrderedList();

    //Inserts a new node into the list, properly sorted into list, ignores duplicates
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
