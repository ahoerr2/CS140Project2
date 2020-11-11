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

std::string Node::toString()
{
	std::string debugOutput = "Node( Payload: ";
	debugOutput += "\"" + this->payload + "\", ";
	debugOutput += "nextNode: ";
	if (nextNode == nullptr) debugOutput += "nullptr";
	else debugOutput += "true";
	debugOutput += " )";

	return debugOutput;
}