#pragma once

#include <string>

// forward declaration of OrderedList
class OrderedList; //(OrderedList does not exist yet)

class Node
{
    friend class OrderedList;
public:
    explicit Node(const std::string& p);
    void setNextNode(Node* nxtNodePtr);
    Node* getNextNode();
    void setPayload(const std::string& p); //May not be used in project but good practice to have
    std::string getPayload();
private:
    std::string payload;
    Node* nextNode{ nullptr };
};
