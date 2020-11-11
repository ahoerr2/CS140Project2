#pragma once

#include <string>

// forward declaration of OrderedList
//class OrderedList; //(OrderedList does not exist yet, uncomment after ordered list is added)

class Node
{
    //friend class OrderedList; //Allows the ordered list to directly interface with the class
public:
    explicit Node(const std::string& p);
    void setNextNode(Node* nxtNodePtr);
    Node* getNextNode();
    void setPayload(const std::string& p); //May not be used in project but good practice to have
    std::string getPayload();
    std::string toString(); //Creates a formatted debug string of the node ex. Node( Payload: "hi", nextNode: true)
private:
    std::string payload;
    Node* nextNode{ nullptr };
};
