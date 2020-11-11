#include "Node.h"

Node::Node(const std::string& p)
	: nextNode{ nullptr }
{
	this->payload = p;
}

void Node::setNextNode(Node* nxtNodePtr)
{
	this->nextNode = nxtNodePtr;
}

Node* Node::getNextNode()
{
	return this->nextNode;
}


void Node::setPayload(const std::string& p) 
{
	this->payload = p;
}

std::string Node::getPayload() 
{
	return this->payload;
}
