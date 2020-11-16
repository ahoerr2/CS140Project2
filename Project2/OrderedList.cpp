//Source file for the Ordered Linked List Collection

#include "Node.h"
#include "OrderedList.h"
#include <vector>
using namespace std;

OrderedList::OrderedList() : first(nullptr)
{}


//Takes in, sorts, and inserts an input node in the Linked List collection
//Each node is unique, nodes with the same payload are not added
//Nodes are added to heap memory
void OrderedList::insert(Node node)
{
	// list is nullptr or if the first node's payload is > node's payload, it is made the first node
	if (first == nullptr || first->payload > node.payload)
	{
		Node* temp = new Node(node.payload);
		temp->nextNode = first;
		first = temp;
	}
	else
	{
		Node* current = first;
		Node* previous = nullptr;

		// find the next empty node
		while (current != nullptr)
		{
			// current payload is same as node's payload or current payload > node's payload 
			if (current->payload == node.payload || current->payload > node.payload)
				break;

			previous = current;
			current = current->nextNode;
		}

		// node's payload not present in list, insert it before current
		if (current == nullptr || current->payload != node.payload)
		{
			Node* temp = new Node(node.payload);
			previous->nextNode = temp;
			temp->nextNode = current;
		}
	}
}

//Removes a node in the list and returns the removed node
//Returns a blank Node if no node with a matching payload is found
//Takes in a contstant reference of the removal node
Node OrderedList::remove(const Node& node)
{
	Node* current = first;
	Node* previous = nullptr;

	while (current != nullptr)
	{
		// if the current payload = node's payload or if the current payload > node's payload, we leave the loop
		if (current->payload == node.payload || current->payload > node.payload)
			break;

		previous = current;
		current = current->nextNode;
	}

	if (current != nullptr)
	{
		// if the node's payload found, remove the current node
		if (current->payload == node.payload) {
			if (previous == nullptr) // first node is payload
				return removeFront(); // call removeFront
			else
			{
				// set next of previous to the next of current
				previous->nextNode = current->nextNode;
				Node temp(current->payload); // create a temp node to return
				current->nextNode = nullptr;
				// delete the current node
				delete current;
				current = nullptr;

				return temp;
			}
		}
	}

	return Node(""); //there is no node payload found in this case so we return blank
}




//Removes the first node in a list and returns a copy of the node
Node OrderedList::removeFront()
{
	if (first != nullptr)
	{
		Node temp(first->payload); // create a temporary node with first's payload
		// remove the first node
		Node* current = first;
		first = first->nextNode;
		current->nextNode = nullptr;
		delete current;
		return temp;
	}

	return Node("");
}


//removes all nodes from the list
void OrderedList::clear()
{
	Node* node;

	while (first != nullptr)
	{
		node = first;
		first = first->nextNode;
		node->nextNode = nullptr;
		delete node;
		node = nullptr;
	}
}

// Takes in another list by reference, removes its nodes and inserts them into the caller
void OrderedList::absorb(OrderedList& list)
{
	do
	{
		Node current = list.removeFront(); // get the front node
		insert(current); // insert current node into this list
	} while (list.first != nullptr);
}

//Prints a formatted string of the Linked List Collection for debugging
void OrderedList::printOrderedList()
{

	//Special output if the list is empty
	if (isEmpty())
	{
		std::cout << "OrderedList:[*empty*]" << std::endl;
		return;
	}

	//Setup the iterator and grab the payload from the first node
	Node* nodePtrIterator = first;
	std::cout << "OrderedList:[ ";
	std::cout << nodePtrIterator->payload << " ";

	//Iterate through the list and print out all payloads
	while (nodePtrIterator->nextNode != nullptr)
	{
		nodePtrIterator = nodePtrIterator->nextNode;
		std::cout << nodePtrIterator->payload << " ";
	}

	std::cout << "]" << std::endl;

}

//Checks if the list is empty outputs a boolean value
bool OrderedList::isEmpty()
{
	if (first == nullptr) return true;
	return false;
}





// Destructor that deletes all the nodes in the list
OrderedList::~OrderedList()
{
	cout << "Destructor invokes..." << endl;

	Node* node;
	while (first != nullptr)
	{
		node = first;
		first = first->nextNode;
		cout << "Deleting " << node->payload << endl;
		node->nextNode = nullptr;
		delete node;
		node = nullptr;
	}

	cout << "All nodes Destroyed." << endl;
	cout << endl;
}