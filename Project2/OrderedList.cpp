
#include "Node.h"

#include <vector>

using std::vector;

//example vector call yours what you want
vector<Node> vec;


//Functions are useful for interfacing with the nodes (make private)

//Sets the pointer to the next node
//takes in an address to the current node you are looking at and the address to the next node
void setNextNode(Node* currentNode, Node* nxtNode) 
{
	currentNode->nextNode = nxtNode;
}


//Removes the pointer to the next node, takes in address of current node,
//and a address or a new node that it should be linked to (nullptr too)
//Using the memory management of vector to delete next node
void removeNextNode(Node* currentNode, Node* newNxtNode)
{
	//Error fix if currentNode is end of list or without pointer
	if (currentNode->nextNode == nullptr) return;

	//If newNxtNode is a null pointer then the nextNode is the end of the list
	if (newNxtNode == nullptr) vec.pop_back();
	else vec.erase(vec.begin()+ bSearchPos(currentNode->nextNode->payload));


	currentNode->nextNode = newNxtNode;
}

//Binary Search algorithim, the list is ordered
//Returns the integer position in the list, takes in the string payload you want to find
//Starts at beginning of list, outputs not found if list has no elements, returns -1 if element not found 
int bSearchPos(const std::string& p)
{
	if (vec.size() == 0) return -1;

	int start = 0;
	int end = vec.size() - 1;
	int midPart = start + (end) / 2;

	if (vec[midPart].payload == p) return midPart;

	if (p < vec[midPart].payload) bSearchRec(start, midPart - 1, p);

	if (p > vec[midPart].payload) bSearchRec(midPart + 1, end, p);
}

//Recursive calls for the binary search algorithm
int bSearchRec(int start, int end, const std::string& p)
{
	//Base case(Not found)
	if(end < start) return -1;

	int midPart = ((start + end) / 2) + start;

	if (vec[midPart].payload == p) return midPart;

	if (p < vec[midPart].payload) bSearchRec(start, midPart - 1, p);

	if (p > vec[midPart].payload) bSearchRec(midPart + 1, end, p);


}




