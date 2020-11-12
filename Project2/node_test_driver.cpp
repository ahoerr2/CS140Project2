//Use only for testing purposes
#include "Node.h"

#include <iostream>

using namespace std;

int main() {

	Node a{ "a node" };
	Node b{ "b node" };
	Node c{ "c node" };



	cout << a.toString() << endl;
	a.setNextNode(&b);
	cout << a.toString() << endl;
	
	cout << b.toString() << "Checking if b is referencible by a" << endl;

	cout << a.getNextNode()->toString() << "Both this and the last string should match"<< endl;

	b.setNextNode(&c);
	cout << b.toString() << "Checking if b is referencible by a with a next node" << endl;

	cout << a.nextNode->toString() << "Both this and the last string should match" << endl;
}