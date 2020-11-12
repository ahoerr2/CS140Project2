#pragma once

#include <string>

// forward declaration of OrderedList
class OrderedList; //(OrderedList does not exist yet, uncomment after ordered list is added)

class Node
{
    friend class OrderedList; //Allows the ordered list to directly interface with the class
public:

    explicit Node(const std::string& p);

    //Methods are not needed but as the ordered list can directly reference the private vars
    //Used if you want to encapsulate the node
    void setNextNode(Node* nxtNodePtr);
    Node* getNextNode();
    void setPayload(const std::string& p);
    std::string getPayload();

    //Creates a formatted debug string of the node ex. Node( Payload: "hi", nextNode: true)
    std::string toString(); 

    std::string payload;
    Node* nextNode{ nullptr };
private:

};
